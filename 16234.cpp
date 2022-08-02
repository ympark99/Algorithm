#include <iostream>
#include <queue>

using namespace std;

int N, L, R, arr[51][51];
bool visited[51][51];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int>> q;
vector<pair<int, int>> v;

bool flag = true;
int sum = 0;

void bfs(int row, int col) {
	q.push({row, col});
	visited[row][col] = true;

	while (!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrow = tmp.first + dx[i];
			int ncol = tmp.second + dy[i];

			if (nrow >= 0 && ncol >= 0 && nrow < N && ncol < N && !visited[nrow][ncol]) {
                if (abs(arr[nrow][ncol] - arr[tmp.first][tmp.second]) >= L && abs(arr[nrow][ncol] - arr[tmp.first][tmp.second]) <= R) {
					q.push({ nrow, ncol });
					visited[nrow][ncol] = true;

					v.push_back({ nrow, ncol });
					sum += arr[nrow][ncol];
				}
            }
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    int ans = 0;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	while(flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i, j }); 
					sum = arr[i][j];
					bfs(i, j);
				}

				if (v.size() >= 2) {
					flag = true;
					for (int i = 0; i < v.size(); i++) {
						arr[v[i].first][v[i].second] = sum / v.size();
					}
				}
			}
		}
		if(flag) ans++;

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				visited[i][j] = false;
	}
	cout << ans;
}

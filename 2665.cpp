#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n;
int arr[51][51];
int visited[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
	queue<pair<int, int>> q;
	visited[1][1] = 0;
	q.push({1, 1});
	while(!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];
			if(nrow <= 0 || nrow > n || ncol <= 0 || ncol > n)
				continue;

			if(arr[nrow][ncol]) {
				if(visited[nrow][ncol] > visited[row][col]) {
					visited[nrow][ncol] = visited[row][col];
					q.push({nrow, ncol});
				}
			}
			else {
				if(visited[nrow][ncol] > visited[row][col] + 1) {
					visited[nrow][ncol] = visited[row][col] + 1;
					q.push({nrow, ncol});
				}
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	char a;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a;
			arr[i][j] = a - '0';
			visited[i][j] = INF;
		}
	}
	bfs();
	cout << visited[n][n];
}

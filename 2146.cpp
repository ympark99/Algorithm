#include <bits/stdc++.h>

using namespace std;

int N;
int label = 10;
int arr[101][101];
bool check[101][101];
int ans = 987654321;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct point {
	int row;
	int col;
	int num;
	int cnt;
};
queue<point> q;

void bfs(int st_row, int st_col, int st_num, int st_cnt) {
	queue<point> q2;
	q2.push({st_row, st_col, st_num, st_cnt});

	while(!q2.empty()) {
		int row = q2.front().row;
		int col = q2.front().col;
		int num = q2.front().num;
		int cnt = q2.front().cnt;
		check[row][col] = true;
		q2.pop();

		for(int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];

			if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N || check[nrow][ncol] || arr[nrow][ncol] == num)
				continue;

			// 정답
			if(arr[nrow][ncol] >= 10) {
				ans = min(ans, cnt);
				break;
			}
			else if(arr[nrow][ncol] == 0) {
				check[nrow][ncol] = true;
				q2.push({nrow, ncol, num, cnt+1});
			}
		}
	}
}

void dfs(int row, int col) {
	arr[row][col] = label;
	check[row][col] = true;

	for(int i = 0; i < 4; i++) {
		int nrow = row + dy[i];
		int ncol = col + dx[i];

		if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N || check[nrow][ncol])
			continue;

		if(arr[nrow][ncol] == 1)
			dfs(nrow, ncol);
		else if(arr[nrow][ncol] == 0) {
			q.push({row, col, label, 0});
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// 육지 구분하기
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!check[i][j] && arr[i][j] == 1) {
				dfs(i, j);
				label++;
			}
		}
	}

	while(!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		int num = q.front().num;
		int cnt = q.front().cnt;
		q.pop();
		memset(check, 0, sizeof(check));
		bfs(row, col, num, cnt);
	}

	cout << ans << '\n';

	return 0;
}

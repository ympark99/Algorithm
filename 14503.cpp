#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void dfs(int row, int col, int cd) {
	if(arr[row][col] == 0){
		arr[row][col] = 2;
		ans++;
	}

	for(int i = 0; i < 4; i++){
		int nd = (cd + 3 - i) % 4;
		int nx = row + dx[nd];
		int ny = col + dy[nd];

		if(nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if(arr[nx][ny] == 0)
			dfs(nx, ny, nd);
	}    

	int nd = (cd + 2) % 4;
	int nx = row + dx[nd];
	int ny = col + dy[nd];

	if(arr[nx][ny] == 1){
		cout << ans;
		exit(0);
	}
	dfs(nx, ny, cd);
}


int main(void) {
  ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(r, c, d);

	return 0;
}

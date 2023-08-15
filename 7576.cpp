#include <bits/stdc++.h>
 
using namespace std;

int M, N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[1001][1001];
int ans;

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	cin >> M >> N;

	queue<pair<int, int>> q;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 1) {
				q.push({i, j});
			}
		}
	}

	while(!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];

			if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= M)
				continue;

			if(!arr[nrow][ncol]) {
				arr[nrow][ncol] = arr[row][col] + 1;
				q.push({nrow, ncol});
			}
		}		
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!arr[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
			ans = max(ans, arr[i][j]);
		}
	}
	
	cout << ans - 1 << '\n';

    return 0;
}

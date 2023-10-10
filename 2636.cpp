#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool check[100][100];
int N, M;
int time_cnt, last_cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs() {
	time_cnt++;
	queue<pair<int, int>> q;
	q.push({0, 0});
	int melt_cnt = 0;

	while (!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		check[row][col] = true;

		for(int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];

			if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= M || check[nrow][ncol]) continue;

			if(arr[nrow][ncol] == 0) {
				check[nrow][ncol] = true;
				q.push({nrow, ncol});
			}
			else {
				check[nrow][ncol] = true;
				arr[nrow][ncol] = 0;
				melt_cnt++;
			}
		}
	}
	if(!melt_cnt) return true;
	else {
		last_cnt = melt_cnt;
		return false;
	}
}


int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while(true) {
		if(bfs()) break;
		memset(check, 0, sizeof(check));
	}

	cout << --time_cnt << '\n' << last_cnt << '\n';

	return 0;
}

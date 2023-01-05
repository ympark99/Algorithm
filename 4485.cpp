#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int N;
int arr[125][125];
int ans[125][125];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			ans[i][j] = INF;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

	int cnt = 1;
	while(1){

		cin >> N;
		if(!N) break;

		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				cin >> arr[i][j];

		queue<pair<int, int>> q;
		q.push({0, 0});
		init();
		ans[0][0] = arr[0][0];
		while(!q.empty()){
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			
			if(row == N-1 && col == N-1)
				continue;

			for(int i = 0; i < 4; i++){
				int nRow = row + dx[i];
				int nCol = col + dy[i];
				if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
					continue;

				if(ans[nRow][nCol] > ans[row][col] + arr[nRow][nCol]){
					ans[nRow][nCol] = ans[row][col] + arr[nRow][nCol];
					q.push({nRow, nCol});	
				}
			}
		}
		cout << "Problem " << cnt++ << ": " << ans[N-1][N-1] << '\n';
		memset(arr, 0, sizeof(arr));
	}
}

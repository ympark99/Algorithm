#include <iostream>

using namespace std;

int T;
int arr[125 + 1][125 + 1];
int dp[125 + 1][125 + 1] = {0, };

int drow[4] = {1, -1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

int dfs(int row, int col){
	for(int i = 0; i < 4; i++){
		int nrow = row + drow[i];
		int ncol = col + dcol[i];
		if(nrow > -1 || nrow < T || ncol > -1 || ncol < T){
			// dp[row][col] = min(dp[row][col], dfs(nrow, ncol) + arr[row][col]);
			dp[row][col] += (dfs(nrow, ncol) + arr[row][col]);
		}	
	}

	return dp[row][col];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int cnt = 1;
	while(1){
		cin >> T;
		if(!T) break;
		
		for(int i = 0; i < T; i++){
			for(int j = 0; j < T; j++)
				cin >> arr[i][j];
		}

		printf("Problem %d: %d", cnt, dfs(T, T));
		cnt++;
	}
}

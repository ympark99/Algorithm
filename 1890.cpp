#include <bits/stdc++.h>
 
using namespace std;

int N;
int arr[101][101];
long long dp[101][101];

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = 1;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(!dp[i][j] || (i == N && j == N)) continue;

			long long down = i + arr[i][j];
			long long right = j + arr[i][j];

			if(down <= N)
				dp[down][j] += dp[i][j];
			if(right <= N)
				dp[i][right] += dp[i][j];
		}
	}
	
	cout << dp[N][N] << '\n';

    return 0;
}

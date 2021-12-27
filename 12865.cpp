#include <iostream>
#include <algorithm>

using namespace std;

int w[100 + 1];
int v[100 + 1];

int dp[100 + 1][100000 + 1]; // dp[i][j] = i번째 물건까지 봤을때 용량이 j인 가방의 최댓값

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K; // dp[N][K]가 정답

	for(int i = 1; i <= N; i++){
		cin >> w[i] >> v[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if(j - w[i] < 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
		}
	}

	cout << dp[N][K];	

	return 0;
} 

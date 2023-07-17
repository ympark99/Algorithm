#include <bits/stdc++.h>

using namespace std;

int N, M, ans;
int dp[21][201];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	vector<pair<int, int>> chapter(M+1); // day, page

	for(int i = 1; i <= M; i++) {
		cin >> chapter[i].first >> chapter[i].second;
	}

	for(int i = 1; i <= M; i++) {
		int day = chapter[i].first;
		int page = chapter[i].second;
		for(int j = 1; j <= N; j++) {
			if(j - day >= 0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-day] + page);
			else dp[i][j] = dp[i-1][j];

			ans = max(ans, dp[i][j]);
		}
	}

	cout << dp[M][N] << '\n';

	return 0;
}

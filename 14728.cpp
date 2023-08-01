#include <bits/stdc++.h>

using namespace std;

int N, T;
int dp[10001];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> T;
	
	vector<pair<int, int>> v(N+1); // time, score

	for(int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = T; j >= v[i].first; j--) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	cout << dp[T] << '\n';

	return 0;
}

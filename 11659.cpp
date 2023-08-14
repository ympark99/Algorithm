#include <bits/stdc++.h>
 
using namespace std;

int N, M;

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<long> dp(N + 1);
	dp[0] = 0;

	for(int i = 1; i <= N; i++) {
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for(int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[e] - dp[s - 1] << '\n';
	}

    return 0;
}

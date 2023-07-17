#include <bits/stdc++.h>

using namespace std;

int N;
int dp[100001];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;

    for(int i = 1; i <= N; i++){
        dp[i] = i;
        for(int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i-j*j]+1);
    }

	cout << dp[N] << '\n';

	return 0;
}

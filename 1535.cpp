#include <bits/stdc++.h>

using namespace std;

int N, ans;
int dp[101];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	vector<int> happy(N);
	vector<int> lose(N);

	for(int i = 0; i < N; i++)
		cin >> lose[i];

	for(int i = 0; i < N; i++)
		cin >> happy[i];


	for(int i = 0; i < N; i++) {
		for(int j = 100; j > lose[i]; j--) {
			dp[j] = max(dp[j], dp[j - lose[i]] + happy[i]);
		}
	}
	
	cout << dp[100];

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, k;

int dp[10001];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	vector<int> coin(n);
	for(int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for(int i = 0; i < coin.size(); i++) {
		for(int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	}

	cout << dp[k] << '\n';

	return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int dp[10000+1];

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);

//     int n, k; cin >> n >> k;
//     vector<int> v(n);
//     for(int i = 0; i < n; i++)
//         cin >> v[i];

//     dp[0] = 1;

//     for(int i = 0; i < v.size(); i++){
//         for(int j = v[i]; j <= k; j++){
//             dp[j] += dp[j - v[i]];
//         }
//     }
//     cout << dp[k] << '\n';    
//     return 0;
// }

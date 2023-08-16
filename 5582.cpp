#include <bits/stdc++.h>
 
using namespace std;

string str1, str2;
int dp[4001][4001];
int ans;

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	cin >> str1 >> str2;

	str1 = ' ' + str1;
	str2 = ' ' + str2;

	for(int i = 1; i < str1.length(); i++) {
		for(int j = 1; j < str2.length(); j++) {
			if(str1[i] == str2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << '\n';

    return 0;
}

#include <iostream>

using namespace std;

int dp[10000 + 1][4];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	dp[1][1] = 1;
    dp[2][1] = 1;   dp[2][2] = 1;
    dp[3][1] = 1;   dp[3][2] = 1;   dp[3][3] = 1;

	for(int i = 4; i <= 10000; i++){
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i-2][1] + dp[i-2][2];
		dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
	}

	while(T--){
		int num = 0;
		cin >> num;
		cout << dp[num][1] + dp[num][2] + dp[num][3]  << '\n';
	}
}

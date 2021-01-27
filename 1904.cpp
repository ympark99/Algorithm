#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
	cin >> n;
	int dp[n+1];

	
	dp[1] = 1 % 15746;
	dp[2] = 2 % 15746;

	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-2] + dp[i-1]) % 15746;
	}
	
	cout << dp[n];
}

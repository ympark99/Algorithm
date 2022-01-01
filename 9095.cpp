#include <iostream>
#include <vector>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	int dp[11] = {0, };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 4; i <= 10; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	while (T--){
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}	

	return 0;
} 

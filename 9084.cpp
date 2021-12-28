#include <iostream>
#include <vector>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	while (T--){
		int dp[10000 + 1] = {0, };

		int N;
		cin >> N;
		vector<int> coin(N);
		int target;

		for(int i = 0; i < N; i++){
			cin >> coin[i];
		}

		cin >> target;

		dp[0] = 1;
		for(int i = 0; i < N; i++)
			for(int j = coin[i]; j <= target; j++)
				dp[j] += dp[j - coin[i]];

		cout << dp[target] << '\n';
	}	

	return 0;
} 

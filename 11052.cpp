#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	int card[1000 + 1] = {0, };
	int dp[1000 + 1] = {0, }; // dp[i] 는 i개 갖기 위해 지불한 최댓값

	for(int i = 1; i <= N; i++){
		cin >> card[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + card[j]);
	}

	cout << dp[N];

	return 0;
} 

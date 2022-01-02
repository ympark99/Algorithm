#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	int *dp = new int[N + 2](); // dp[i] i일부터의 최댓값

	vector<pair<int, int>> v(N + 2);

	for(int i = 1; i <= N; i++)
		cin >> v[i].first >> v[i].second;	

	for(int i = N; i >= 1; i--){
		if(v[i].first > N - i + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], v[i].second + dp[i + v[i].first]);		
	}

	cout << dp[1];

	return 0;
} 

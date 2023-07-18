#include <bits/stdc++.h>

using namespace std;
int dp[1001]; // N번 건물까지 짓는데 드는 최소 시간

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		int N, K, W;
		cin >> N >> K;

		queue<int> q;
		vector<int> cost(N+1);
		vector<int> nextStep[1001];
		int inDeg[1001] = {0, }; // 진입차수
		for(int i = 1; i <= N; i++)
			cin >> cost[i];

		for(int i = 1; i <= K; i++) {
			int pre, next;
			cin >> pre >> next;
			nextStep[pre].push_back(next);
			inDeg[next]++;
		}

		cin >> W;

		for(int i = 1; i <= N; i++) {
			if(!inDeg[i])
				q.push(i);
			dp[i] = cost[i];
		}

		while(!q.empty()) {
			int cur = q.front();
			q.pop();

			for(int i = 0; i < nextStep[cur].size(); i++) {
				int next = nextStep[cur][i];
				inDeg[next]--;
				dp[next] = max(dp[next], dp[cur] + cost[next]);

				if(!inDeg[next])
					q.push(next);
			}
		}

		cout << dp[W] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}

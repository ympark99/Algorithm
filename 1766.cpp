#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int N, M;
vector<int> nextStep[32001];
int inDeg[32001];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		nextStep[a].push_back(b);
		inDeg[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 1; i <= N; i++) {
		if(!inDeg[i])
			pq.push(i);
	}

	while(!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		
		cout << cur << ' ';

		for(int i = 0; i < nextStep[cur].size(); i++) {
			int next = nextStep[cur][i];
			inDeg[next]--;
			if(!inDeg[next])
				pq.push(next);
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int V, E, K;
int dist[20001];
vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra() {
	pq.push({0, K});
	dist[K] = 0;

	while(!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for(int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int ncost = edge[cur][i].second;

			if(dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({dist[next], next});
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> K;

	for(int i = 0; i < 20001; i++)
		dist[i] = INF;

	for(int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
	}

	dijkstra();

	for(int i = 1; i <= V; i++) {
		if(dist[i] == INF)
			cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}

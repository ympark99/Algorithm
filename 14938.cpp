#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int n, m, r;
int ans;
int dist[101];
vector<pair<int, int>> edge[101];

void find_item(int start, vector<int> items) {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(dist[i] <= m) {
			sum += items[i];
		}
	}
	ans = max(ans, sum);
}

void dijkstra(int start) {
	for(int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start] = 0;

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

	cin >> n >> m >> r;

	vector<int> items(n+1);

	for(int i = 1; i <= n; i++) {
		cin >> items[i];
	}

	for(int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		edge[a].push_back({b, l});
		edge[b].push_back({a, l});
	}

	for(int i = 1; i <= n; i++) {
		dijkstra(i);
		find_item(i, items);
	}
	cout << ans << '\n';

	return 0;
}

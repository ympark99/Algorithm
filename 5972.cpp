#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> v[50000+1]; // end, cost
vector<int> dist(50000+1, INT_MAX);

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second; 
        pq.pop();

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;
            if(dist[next] > cost + nCost){
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra(1);
    cout << dist[N];
}

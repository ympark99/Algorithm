#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

vector<pair<int, int>> v[801];
vector<int> dist(801, INF);
int v1, v2, N, E;
int res = INF;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > dist[cur]) continue;

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

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> E;

    int a, b, c = 0;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int s2v1, s2v2, v12v2, v12n, v22n;

    dijkstra(1);
    s2v1 = dist[v1];
    s2v2 = dist[v2];

    dijkstra(v1);
    v12v2 = dist[v2];
    v12n = dist[N];

    dijkstra(v2);
    v22n = dist[N];

    res = min(res, s2v1 + v12v2 + v22n);
    res = min(res, s2v2 + v12v2+ + v12n);
    if(v12v2 == INF || res == INF) 
        cout << -1;
    else cout << res;
}

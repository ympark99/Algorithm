#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999999

int N, M, X;
vector<pair<int, int>> v[1000+1];
vector<int> dist(1000+1, INF);

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty()){
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({end, cost});
    }

    dijkstra(X);

    vector<int> dist_final = dist;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(i == X) continue;
        dijkstra(i);
        dist_final[i] += dist[X];
        ans = max(ans, dist_final[i]);
    }
    cout << ans; 
}

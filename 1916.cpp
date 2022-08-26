#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

vector<pair<int, int>> v[1000+1];
vector<int> dist(1000+1, INF);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({end, cost});
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost)
            continue;
        
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;
            if(dist[next] > cost + nCost){
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }

    cout << dist[end];
}

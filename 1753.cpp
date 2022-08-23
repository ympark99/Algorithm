#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000
#define MAX_VERTEX 20001
#define MAX_EDGE 300001

using namespace std;

int d[MAX_VERTEX];

vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start_node){
    d[start_node] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start_node));

    while(!pq.empty()){
        int current = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if (d[current] < cost){
            continue;
        }

        for (int i=0; i < edge[current].size(); ++i){
            int next = edge[current][i].second;
            int nCost = cost + edge[current][i].first;

            if (d[next] > nCost){
                d[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    int start_node;
    cin >> start_node;

    for (int i=1; i<v+1; ++i){
        d[i] = INF;
    }

    for (int i = 0; i < e; ++i){
        int start, end, cost;
        cin >> start >> end >> cost;

        edge[start].push_back(make_pair(cost, end));
    }

    dijkstra(start_node);

    for (int i=1; i<v+1; ++i){
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
vector<int> dist;

int V, E, start;

int getMinIdx(){
    int min = INF;
    int idx = 1;
    for(int i = 1; i <= V; i++){
        if(dist[i] < min && !visited[i]){
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    cin >> start;

    arr.resize(V+1, vector<int>(V+1, INF));
    visited.resize(V+1, false);
    dist.resize(V+1);

    int a, b, c;
    for(int i = 1; i <= E; i++){
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for(int i = 1; i <= V; i++){
        dist[i] = arr[start][i];
    }
    dist[start] = 0;
    visited[start] = true;

    for(int i = 1; i <= V - 1; i++){
        int cur = getMinIdx();
        visited[cur] = true;
        for(int j = 1; j <= V; j++){
            if(visited[j])
                continue;
            if(dist[cur] + arr[cur][j] < dist[j])
                dist[j] = dist[cur] + arr[cur][j];
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == INF)
            cout << "INF\n";
        else cout << dist[i] << '\n';
    }

}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 100000+1

using namespace std;

int N, K;
bool visited[MAX_SIZE];

int dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});

    while (!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == K) return cost;

        if(cur * 2 < MAX_SIZE && !visited[cur * 2]){
            pq.push({cost, cur * 2});
            visited[cur * 2] = true;
        }

        if(cur + 1 < MAX_SIZE && !visited[cur + 1]){
            pq.push({cost + 1, cur + 1});
            visited[cur + 1] = true;
        }

        if(cur - 1 >= 0 && !visited[cur - 1]){
            pq.push({cost + 1, cur - 1});
            visited[cur - 1] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    cout << dijkstra();
}

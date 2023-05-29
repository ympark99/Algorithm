#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int ansNum = 1, ansDist = 0, ansCnt = 0;
vector<int> graph[50001];
vector<bool> check(50001);

void bfs(){
    queue<pair<int, int>> q;
    q.push({1, 0});

    while(!q.empty()){
        int now = q.front().first;
        int dist = q.front().second;
        check[now] = true;
        q.pop();

        if(dist > ansDist) {
            ansDist = dist;
            ansNum = now;
            ansCnt = 1;
        }
        else if(dist == ansDist){
            ansNum = min(ansNum, now);
            ansCnt++;
        }

        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i];
            if(!check[next]){
                check[next] = true;
                q.push({next, dist+1});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    cout << ansNum << " " << ansDist << " " << ansCnt << '\n';

	return 0;
}

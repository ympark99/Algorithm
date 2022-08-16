#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<int> v[N + 1];
    vector<int> inDegree(N + 1, 0);
    queue<int> q;

    while(M--){
        pair<int, int> p;
        cin >> p.first >> p.second;
        v[p.first].push_back(p.second);
        inDegree[p.second]++;
    }
    // q에 삽입
    for(int i = 1; i <= N; i++){
        if(!inDegree[i])
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if(!--inDegree[next])
                q.push(next);
        }
    }
}

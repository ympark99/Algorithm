#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> check;
vector<int> answer;
int N, M, start;

void print(){
    for(auto elem : answer) cout << elem << " ";
    return;
}

void dfs(int now, int cnt, vector<vector<bool>> v){
    check[now] = true;
    answer.push_back(now);
    cnt++;

    if(M == cnt) return;

    for(int i = 1; i < v.size(); i++){
        if(check[i]) continue;
        if(v[now][i]){
            v[now][i] = 0;
            v[i][now] = 0;
            dfs(i, cnt, v);
        }
    }
    return;
}

void bfs(int now, int cnt, queue<int> q, vector<vector<bool>> v){
    if(q.empty() || M == cnt) return;

    for(int i = 1; i < v.size(); i++){
        if(check[i]) continue;
        if(v[now][i]){
            cnt++;
            q.push(i);
            check[i] = true;
            answer.push_back(i);
        }
    }
    q.pop();
    bfs(q.front(), cnt, q, v);   

    return;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> start;

    vector<vector<bool>> v(N + 1, vector<bool>(N + 1, 0));
    queue<int> q;

    check.resize(N + 1, 0);

    while(M--){
        int y, x;
        cin >> y >> x;
        v[y][x] = 1;
        v[x][y] = 1;
    }
    
    dfs(start, 0, v);
    print();
    cout << '\n';
    answer.clear();
    check.clear();
    check.resize(N + 1, 0);

    answer.push_back(start);
    check[start] = true;
    q.push(start);

    bfs(start, 1, q, v);
    print();

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = -1;

void bfs(vector<vector<int>> v){
    queue<pair<int, int>> q;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX > -1 && nextX < v.size() && nextY > -1 && nextY < v[x].size() && v[nextX][nextY] == 0){
                q.push(make_pair(nextX, nextY));
                v[nextX][nextY] = 2;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++)
            if(!v[i][j]) cnt++;
    }
    if(cnt > ans) ans = cnt;
}

// 벽 3개 조합 함수
void dfs(vector<vector<int>> v, int x, int y, int wall){
    v[x][y] = 1;
    if(wall == 3){
        bfs(v);
        return;
    }

    for(int i = x; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(!v[i][j])
                dfs(v, i, j, wall + 1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            scanf("%d", &v[i][j]);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!v[i][j]){
                dfs(v, i, j, 1);
            }
        }
    }
    cout << ans;
}

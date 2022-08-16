#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ans = 0;

char mat[5][5];
int g[5][5];
int isVisited[5][5];
int isSelected[26];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool isValid(int y, int x){
    return (y >= 0 && y < 5) && (x >= 0 && x < 5);
}

// 연결되었는지 확인  
bool check(){
    
    memset(g, 0, sizeof(g));
    memset(isVisited, 0, sizeof(isVisited));
    
    int y, x;
    for(int i = 0; i < 25; i++){
        if(isSelected[i] == 0) continue;
        y = i / 5;
        x = i % 5;
        g[y][x] = 1;
    }
    
    queue<pair<int, int> > q;
    q.push({y, x});
    isVisited[y][x] = 1;
    
    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int ny = y + dir[d][0];
            int nx = x + dir[d][1];
            
            if(!isValid(ny, nx)) continue;
            if(isVisited[ny][nx]) continue;
            
            if(g[ny][nx] == 1) {
                cnt++;
                q.push({ny, nx});
                isVisited[ny][nx] = 1;
            }
        }
    }
    
    if(cnt == 7) return true;
    else return false;
}

void dfs(int idx, int total, int cnt_s){
    
    if(total == 7){
        if(cnt_s >= 4){
            if(check()) ans++;
        }
        return;
    }
    
    for(int i=idx; i<25; i++){
        if(isSelected[i]) continue;
        
        isSelected[i] = 1;
        dfs(i, total+1, cnt_s + (mat[i/5][i%5] == 'S'));
        isSelected[i] = 0;
    }
}

int main(void){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> mat[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << ans << endl;
}

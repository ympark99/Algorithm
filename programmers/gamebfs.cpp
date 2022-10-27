#include<bits/stdc++.h>

using namespace std;

struct game{
    int row;
    int col;
    int cnt;
};

int answer = 987654321;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];

int solution(vector<vector<int> > maps)
{
    int m = maps.size();
    int n = maps[0].size();
    queue<game> q;
    q.push({0, 0, 1});
    memset(visited, false, sizeof(visited));
    
    while(!q.empty()){
        int row = q.front().row;
        int col = q.front().col;
        int cnt = q.front().cnt;
        visited[row][col] = true;
        q.pop();
        
        if(row == m - 1 && col == n - 1){
            answer = min(answer, cnt);
        }
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dy[i];
            int ncol = col + dx[i];
            
            if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || visited[nrow][ncol])
                continue;
            if(!maps[nrow][ncol]) continue;
            
            q.push({nrow, ncol, cnt+1});
            visited[nrow][ncol] = true;
        }       
    }
    
    if(answer == 987654321) answer = -1;
    return answer;
}

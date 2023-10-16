#include <bits/stdc++.h>

using namespace std;

pair<int, int> now, target;
bool check[101][101];
int answer = -1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct point {
    int row;
    int col;
    int cnt;
};

void bfs(vector<string> board) {
    queue<point> q;
    q.push({now.first, now.second, 0});
    check[now.first][now.second] = true;
    
    while(!q.empty()) {
        int row = q.front().row;
        int col = q.front().col;
        int cnt = q.front().cnt;
        q.pop();
        
        if(row == target.first && col == target.second) {
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nrow = row;
            int ncol = col;
            while(1) {
                nrow += dy[i];
                ncol += dx[i];
                
                if(nrow < 0 || nrow >= board.size() || ncol < 0 || ncol >= board[0].size() || board[nrow][ncol] == 'D') {
                    nrow -= dy[i];
                    ncol -= dx[i];                    
                    break;
                }
            }
                
            if(check[nrow][ncol]) continue;

            q.push({nrow, ncol, cnt+1});
            check[nrow][ncol] = true;
        }
    }
}

int solution(vector<string> board) {
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 'R') {
                now = {i, j};
            }
            else if(board[i][j] == 'G') {
                target = {i, j};
            }
        }
    }
    
    bfs(board);
    
    return answer;
}

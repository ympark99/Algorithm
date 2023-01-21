#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int R, C;
char arr[1000][1000];
int fire[1000][1000];
bool visit[1000][1000];

queue<pair<int, int>> fire_q; // row, col
pair<int,int> start;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct moves{
    int row;
    int col;
    int cnt;
};

void make_fire(){
    while(!fire_q.empty()){
        int row = fire_q.front().first;
        int col = fire_q.front().second;
        fire_q.pop();

        for(int i = 0; i < 4; i++){
            int nRow = row + dy[i];
            int nCol = col + dx[i];
            if(nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || arr[nRow][nCol] == '#')
                continue;
            if(fire[nRow][nCol] > fire[row][col] + 1){
                fire[nRow][nCol] = fire[row][col] + 1;
                fire_q.push({nRow, nCol});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            fire[i][j] = INT_MAX;
            cin >> arr[i][j];
            if(arr[i][j] == 'J'){
                start.first = i;
                start.second = j;
            }
            else if(arr[i][j] == 'F'){
                fire_q.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    make_fire();

    queue<moves> q;
    q.push({start.first, start.second, 0});
    visit[start.first][start.second] = true;
    bool flag = false;
    while(!q.empty()){
        int row = q.front().row;
        int col = q.front().col;
        int cnt = q.front().cnt;
        q.pop();
        visit[row][col] = true;

        if(row == 0 || row == R-1 || col == 0 || col == C-1){
            cout << cnt + 1;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nRow = row + dy[i];
            int nCol = col + dx[i];
            if(nRow < 0 || nRow >= R || nCol < 0 || nCol >= C || arr[nRow][nCol] == '#' || visit[nRow][nCol])
                continue;

            if(fire[nRow][nCol] > cnt + 1){
                visit[nRow][nCol] = true;
                q.push({nRow, nCol, cnt+1});
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

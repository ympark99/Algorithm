#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int M, N;
int arr[101][101];
vector<vector<int>> dist(101, vector<int>(101, INT_MAX));
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(){
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nRow = row + dy[i];
            int nCol = col + dx[i];
            if(nRow <= 0 || nRow > N || nCol <= 0 || nCol > M)
                continue;
            if(arr[nRow][nCol] == 1 && (dist[nRow][nCol] > dist[row][col] + 1)){
                dist[nRow][nCol] = dist[row][col] + 1;
                q.push({nRow, nCol});
            }
            else if(!arr[nRow][nCol] && (dist[nRow][nCol] > dist[row][col])){
                dist[nRow][nCol] = dist[row][col];
                q.push({nRow, nCol});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char ch;
            cin >> ch;
            arr[i][j] = ch - '0';
        }
    }
    bfs();
    cout << dist[N][M];
    return 0;
}

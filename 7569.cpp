#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
    int a, b, c;
    int cnt;
} locate;

int M, N, H;
int ans;

int arr[100+1][100+1][100+1];
bool visited[100+1][100+1][100+1] = {false, };
queue<locate> q;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> M >> N >> H;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({i, j, k, 0});
                    visited[i][j][k] = true;
                }
                else if(arr[i][j][k] == -1)
                    visited[i][j][k] = true;
            }
        }
    }
    
    if(q.empty()){
        cout << -1;
        return 0;
    }

    int ans = 0;
    while (!q.empty()){
        int hei = q.front().a;
        int row = q.front().b;
        int col = q.front().c;
        int cnt = q.front().cnt;
        ans = max(ans, cnt);
        q.pop();

        for(int i = 0; i < 6; i++){
            int nRow = row + dy[i];
            int nCol = col + dx[i];
            int nHei = hei + dz[i];
            if(nRow < 1 || nRow > N || nCol < 1 || nCol > M || nHei < 1 || nHei > H)
                continue;
            if(!visited[nHei][nRow][nCol] && !arr[nHei][nRow][nCol]){
                arr[nHei][nRow][nCol] = 1;
                visited[nHei][nRow][nCol] = true;
                q.push({nHei, nRow, nCol, cnt+1});
            }
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= M; k++){
                if(arr[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

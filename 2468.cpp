#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[101][101];
bool check[101][101];
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int a, int b){
    ans++;
    queue<pair<int, int>> q;
    q.push({a, b});

    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        check[row][col] = true;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dy[i];
            int ncol = col + dx[i];
            if(nrow < 1 || nrow > N || ncol < 1 || ncol > N) continue;

            if(!check[nrow][ncol]){
                q.push({nrow, ncol});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            if(arr[i][j] <= N){
                arr[i][j] = 0;
                check[i][j] = true;
            }
            else arr[i][j] = 1;
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!check[i][j])
                bfs(i, j);
        }
    }
    cout << ans;
}

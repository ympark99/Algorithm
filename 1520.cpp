#include <iostream>
#include <memory.h>

using namespace std;

const int MAXN = 500;

int arr[MAXN+1][MAXN+1] = {0,};
int dp[MAXN+1][MAXN+1];
int lr[4] = { -1,0,1,0 };
int ud[4] = { 0,-1,0,1 };

int m, n;

int dfs(int row, int col){
    if (row == 1 && col == 1) return 1;
 
    if (dp[row][col] == -1) {
        dp[row][col] = 0;
        
        for (int i = 0; i < 4; i++) {
            int nxRow = lr[i] + row;
            int nxCol = ud[i] + col;
 
            if (nxRow >= 1 && nxRow <= m && nxCol >= 1 && nxCol <= n) {
                if (arr[row][col] < arr[nxRow][nxCol])
                    dp[row][col] += dfs(nxRow, nxCol);
            }
        }
    }
    return dp[row][col];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> m >> n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(m, n);

    return 0;
}

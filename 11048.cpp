#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int maze[MAXN + 1][MAXN + 1] = {0, };
int dp[MAXN + 1][MAXN + 1];

void solve(int n, int m){
    dp[1][1] = maze[1][1];
/*
    for(int i = 2; i <= n; i++){
        dp[i][1] = dp[i-1][1] + maze[i][1];
        for(int j = 2; j <= m; j++){
            dp[1][j] = dp[1][j-1] + maze[1][j];            
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + maze[i][j];
        }
    }
*/

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int Result = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            dp[i][j] = Result + maze[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maze[i][j];
        }
    }

    solve(n, m);

    cout << dp[n][m];

    return 0;
}

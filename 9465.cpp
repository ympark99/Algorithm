#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n, 0));
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }

        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        dp[0][1] = v[0][1] + dp[1][0];
        dp[1][1] = v[1][1] + dp[0][0];

        for(int i = 2; i < n; i++){
            dp[0][i] = v[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = v[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }
}

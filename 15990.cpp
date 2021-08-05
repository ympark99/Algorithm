#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
const int divide = 1e9 + 9;
ll dp[MAXN + 1][3 + 1] = {0,};

void solve(){
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i <= MAXN; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % divide;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % divide;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % divide;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;

    solve();

    while(T--){
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }

    return 0;
}

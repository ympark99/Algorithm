#include <iostream>

using namespace std;

int dp[1000+1][10];
int ans;

int main(){

    int N; cin >> N;
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++)
                dp[i][j] += dp[i-1][k];
            dp[i][j] %= 10007;
        }
    }
    for(int i = 0; i < 10; i++)
        ans = (ans + dp[N][i]) % 10007;

    cout << ans % 10007;
}

#include <iostream>

using namespace std;

long long dp[201][201];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, K; cin >> N >> K;
    for(int i = 0; i <= N; i++){
        dp[1][i] = 1;
        dp[2][i] = i+1;
    }
    for(int i = 3; i <= K; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % 1000000000;
        }
    }
    cout << dp[K][N] << '\n';
    return 0;
}

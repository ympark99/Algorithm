#include <bits/stdc++.h>
 
using namespace std;

int N;
int dp[1000]; // 0: sk, 1: cy

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1] + 1, dp[i-3] + 1);
    }
    
    if(dp[N] % 2 == 1)
        cout << "SK\n";
    else cout << "CY\n";

    return 0;
}

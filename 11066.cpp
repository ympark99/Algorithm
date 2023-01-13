#include <bits/stdc++.h>

using namespace std;

int dp[501][501], sum[501], file[501];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int num;
        cin >> num;
        for(int i = 1; i <= num; i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for(int i = 1; i <= num; i++){
            for(int j = 1; j <= num - i; j++){
                dp[j][i+j] = INT_MAX;
                for(int k = j; k < i + j; k++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }
        cout << dp[1][num] << '\n';
    }
	return 0;
}

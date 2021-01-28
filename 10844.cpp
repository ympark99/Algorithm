#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


        int n;
        cin >> n;
        long sum = 0;

        long dp[n][10] = {0,};

        for(int i=0; i<10;i++){
            if(i == 0) dp[0][i] = 0;
            else dp[0][i] = 1;
            if(n == 1) sum += dp[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<10; j++){
                if(j == 0) dp[i][j] = dp[i-1][j+1];
                else if(j == 9) dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                if(i == n-1) sum += dp[i][j];
            }
        }       

        cout << sum % 1000000000;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[500][500] = {0,};
    int dp[500][500] = {0,};

    int n;
    int row = 1;
    int res = -1;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for(int j=0; j<row; j++){
            cin >> arr[i][j];
        }
        row++;
    }


    dp[0][0] = arr[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0) dp[i][j] = arr[i][j] + dp[i-1][j];
            else if(j == i) dp[i][j] = arr[i][j] + dp[i-1][j-1];
            else dp[i][j] = arr[i][j] + max(dp[i-1][j-1],dp[i-1][j]);            
        }
    }

    for(int i=0; i<n; i++){
        res = max(res, dp[n-1][i]);
    }

    cout << res;
    return 0;
}

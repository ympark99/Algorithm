#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    int res;
    cin >> n;

    int* arr = new int[n+1];
    int* dp = new int[n+1];

    dp[1] = 0;

    for(int i=2; i<=n; i++){
        if(i % 3 == 0)  dp[i] = min(dp[i/3],dp[i-1]) + 1;
        else if(i % 2 ==0) dp[i] = min(dp[i/2],dp[i-1]) + 1;
        else dp[i] = dp[i-1] + 1;     
    }

    cout << dp[n];
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    int res;
    cin >> n;

    vector<int> v(n);
    vector<int> dp(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    dp[0] = v[0];
    res = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1]+v[i],v[i]);
        res = max(res,dp[i]);
    }

    cout << res;
}

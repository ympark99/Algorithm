#include <bits/stdc++.h>

using namespace std;

vector<int> dp(10000+1, INT_MAX);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    set<int> s;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        s.insert(num);
    }

    for(auto elem : s){
        dp[elem] = 1;
        for(int j = elem + 1; j <= k; j++){
            if(dp[j - elem] == INT_MAX) continue;
            dp[j] = min(dp[j], dp[j - elem] + dp[elem]);
        }
    }

    if(dp[k] == INT_MAX) cout << -1;
    else cout << dp[k];
}

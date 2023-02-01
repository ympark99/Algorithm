#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> dp(N+2, 0);
    vector<pair<int, int>> v(N+2);

    for(int i = 1; i <= N; i++)
        cin >> v[i].first >> v[i].second;

    for(int i = N; i > 0; i--){
        int cost = v[i].first;
        int reward = v[i].second;
        if(i + cost > N+1){
            dp[i] = dp[i+1];
        }
        else
            dp[i] = max(dp[i+1], dp[i + cost] + reward);
        
    }
    cout << dp[1] << '\n';
}

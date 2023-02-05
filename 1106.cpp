#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000 * 100 +1]; // 비용 i일때 최대 고객

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int C, N;
    cin >> C >> N;
    vector<pair<int, int>> v(N+1);
    for(int i = 1; i <= N; i++){
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 1; i <= 100000; i++){
        for(int j = 1; j <= N; j++){
            if(i % v[j].first == 0){
                dp[i] = max(dp[i], v[j].second * (i / v[j].first));
            }
            if(i - v[j].first >= 0){
                dp[i] = max(dp[i], dp[i-v[j].first] + v[j].second);
            }
        }
        if(C <= dp[i]){
            cout << i;
            return 0;
        }
    }
}

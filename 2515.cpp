#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[300000 + 1] = {0,};

int comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,s;
    cin >> n >> s;

    vector<pair<int, int>> v;
    v.resize(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    dp[1] = v[1].second;

    int lastIdx = 1;
    
    for(int i = 2; i <= n; i++){
        if(v[i].first - v[lastIdx].first >= s){
            dp[i] = dp[lastIdx] + v[i].second;
            lastIdx = i;
        }
        else{
            int cnt = 1;
            for(int j = i - 1; j >= 1; j--){
                if(v[i].first - v[j].first >= s) break;
                cnt++;
            }

            if(v[i].second + dp[i-cnt] > dp[i-1]){
                dp[i] = dp[i-cnt] + v[i].second;
                lastIdx = i;
            }
            else dp[i] = dp[i-1];
        }
        //cout << lastIdx << " " << dp[i] << '\n';
    }

    cout << dp[n];

    return 0;
}

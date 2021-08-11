#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end(), comp);

    vector<int> dp(v.size());

    int res = 0;
    for(int i = 0; i < v.size(); i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }

    cout << n - res;    

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    int res;
    cin >> n;
    vector<int> v;
    int* dp = new int[n];

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    dp[0] = v.front();
    int sum = dp[0];

    for(int i=1; i<n; i++){
        dp[i] = dp[i-1] + v[i];
        sum += dp[i];
    }

    cout << sum;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[100001];
int ans, start;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        cnt[v[i]]++;
        while(cnt[v[i]] > K){
            cnt[v[start++]]--;
        }
        ans = max(ans, i - start + 1);
    }
    cout << ans << '\n';
    return 0;
}

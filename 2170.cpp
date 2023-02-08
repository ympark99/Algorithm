#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000010

using namespace std;

int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());

    int start = -INF, end = -INF;
    for(int i = 0; i < N; i++){
        if(v[i].first > end){
            ans += v[i].second - v[i].first;
            start = v[i].first;
            end = v[i].second;
        }
        else if(v[i].second > end){
            ans += v[i].second - end;
            end = v[i].second;
        }
    }
    cout << ans << '\n';
}

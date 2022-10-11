#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, D;
    cin >> N >> D;
    vector<int> map(D+1, 999999999);
    vector<pair<int, int>> v[10001];
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[b].push_back({a,c});
    }
    map[0] = 0;
    for(int i = 1; i <= D; i++){
        if(!v[i].size())
            map[i] = map[i-1] + 1;
        else{
            for(auto elem : v[i])
                map[i] = min(map[i], min(map[i-1]+1, map[elem.first] + elem.second));
        }
    }
    cout << map[D] << '\n';
    return 0;
}

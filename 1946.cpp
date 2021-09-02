#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        int n;
        cin >> n;

        vector<pair<int, int>> v;

        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }
        
        sort(v.begin(), v.end());

        int cnt = 0;
        int mini = v[0].second;
        for(int i = 1; i < v.size(); i++){
            if(v[i].second > mini) cnt++;
            else if(v[i].second < mini) mini = v[i].second;
        }
        cout << n - cnt << '\n';
    }   
    return 0;
}

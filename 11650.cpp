#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int,int>> xy;

    for(int i = 0 ; i<n; i++){
        int num[2];
        for(int j=0; j<2; j++){
            cin >> num[j];
        }
        xy.push_back(make_pair(num[0],num[1]));
    }

    sort(xy.begin(),xy.end());

    for(int i =0; i<xy.size();i++)
        cout << xy[i].first << " " << xy[i].second << "\n";

    return 0;
}

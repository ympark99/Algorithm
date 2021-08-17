#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, y;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> y;
        if(v.empty() || v.back() < y) v.push_back(y);
        else{
            auto iter =  lower_bound(v.begin(), v.end(), y);
            *iter = y;
        }
    }

    cout << n - (int)(v.size());
    return 0;
}

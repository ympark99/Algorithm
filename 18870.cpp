#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int N;
    cin >> N;
    vector<int> v, idx;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
        idx.push_back(num);
    }
    
    sort(idx.begin(), idx.end());
    idx.resize(unique(idx.begin(), idx.end()) - idx.begin());

    for(auto elem : v){
        int result = lower_bound(idx.begin(), idx.end(), elem) - idx.begin();
        cout << result << ' ';
    }
    return 0;
}

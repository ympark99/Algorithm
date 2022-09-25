#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    vector<int> v(N);
    vector<int> lcs;

    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    int start = 0, end = 0, cnt = 0, ans = 0;
    int last = 0;
    
    for(int i = 0; i < N; i++){
        if(!lcs.size() || lcs[lcs.size()-1] < v[i])
            lcs.push_back(v[i]);
        else{
            // int left = 0;
            // int right = lcs.size()-1;
            // while (left < right){
            //     int mid = (left + right) / 2;
            //     if(lcs[mid] >= v[i])
            //         right = mid;
            //     else left = mid + 1;
            // }
            // lcs[left] = v[i];

            int idx = lower_bound(lcs.begin(), lcs.end(), v[i]) - lcs.begin();
            lcs[idx] = v[i];
        }
    }
    cout << lcs.size() << '\n';
    return 0;
}

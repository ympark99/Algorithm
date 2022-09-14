#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int low = 0, high = N-1;
    pair<int, int> ans;
    int mins = 2000000000;
    while (low < high){
        int sum = v[low] + v[high];
        if(abs(sum) < mins){
            mins = abs(sum);
            ans.first = v[low];
            ans.second = v[high];
            if(sum == 0) break;
        }
        if(sum < 0) low++;
        else high--;
    }
    cout << ans.first << " " << ans.second;
    return 0;
}

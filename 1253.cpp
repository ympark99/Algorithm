#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        int target = v[i];
        int start = 0;
        int end = N-1;

        int sum = 0;
        while (start < end){
            sum = v[start] + v[end];
            if(sum == target){
                if(start != i && end != i){
                    ans++;
                    break;
                }
                else if(start == i) start++;
                else if(end == i) end--;
            }
            else if(sum > target) end--;
            else start++;
        }        
    }    
    cout << ans;
    return 0;
}

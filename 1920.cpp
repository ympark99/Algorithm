#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
void binary(int target, vector<int> v){

    int left = v.front();
    int right = v.back();

    while (left <= right){
        int mid = (left + right) / 2;
        if(mid == target){
            cout << 1 << "\n";
            return;
        }
        else if(mid > target){
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << 0 << "\n";    
    return;
}
*/
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> M;    
    sort(v.begin(), v.end());

    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        //binary(target, v);
        if(binary_search(v.begin(),v.end(),target)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}

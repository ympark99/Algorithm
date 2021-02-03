#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<int> v;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int remain = k;
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(v[i] <= remain){
            cnt += remain/v[i];
            remain = remain%v[i]; 
        }
    }

    cout << cnt;
}

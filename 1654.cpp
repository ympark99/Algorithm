#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(long long mid, vector<long long> v, int M){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += v[i] / mid;
    }
    if(cnt >= M) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K, M;
    cin >> K >> M;
    vector<long long> v(K);

    for(int i = 0; i < K; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long left = 1;
    long long right = v.back();
    long long result = 1;

    while (left <= right){
        long long mid = (left + right) / 2;
        if(possible(mid, v, M)){
            if(result < mid) result = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << result;
    return 0;
}

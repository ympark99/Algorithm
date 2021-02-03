#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v;
    vector<long long> vsort;
    vector<long long> length;
    long long sum = 0;

    for(int i=0; i<n-1; i++){
        long long num;
        cin >> num;
        length.push_back(num);
        sum += num;
    }

    for(int i=0; i<n-1; i++){
        long long num;
        cin >> num;
        v.push_back(num);
        vsort.push_back(num);
    }

    sort(vsort.begin(), vsort.end());

    long long res = 0;
    int cnt = 0;
    for(int i=0; i<n-1; i++){
        if(v[i] == vsort[0]){
            res += v[i] * sum;
            cout << res;
            return 0;
        }
        else{
            if(v[i] < v[cnt]){
                res += v[i] * length[i];
                sum -= length[i];
                cnt = i;
            }
            else{
                res += v[cnt] * length[i];
                sum -= length[i];
            }
        }
    }
}

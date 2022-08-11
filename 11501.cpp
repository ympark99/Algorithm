#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;

        vector<int> v(N);

        for(int i = 0; i < N; i++)
            cin >> v[i];

        long long sum = 0;
        int high = 0;
        for(int i = N-1; i >= 0; i--){
            if(v[i] >= high){
                high = v[i];
            }
            else{
                sum += (high - v[i]);
            }
        }
        cout << sum << '\n';
    }    
}

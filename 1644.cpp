#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    vector<int> v;
    vector<bool> check(N+1, true);

    for(int i = 2; i <= sqrt(N); i++){
        if(check[i]){
            for(int j = i + i; j <= N; j += i)
                check[j] = false;
        }
    }

    for (int i = 2; i < N + 1; i++) {
        if(check[i]) 
            v.push_back(i);
    }

    int start = 0, end = 0, sum = 0, ans = 0;

    while (1){
        if(sum >= N)
            sum -= v[start++];
        else if(end == v.size())
            break;
        else
            sum += v[end++];
        if(sum == N) ans++;
    }

    cout << ans << '\n';

    return 0;
}

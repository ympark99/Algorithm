#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;

    while(T--){
        int N, M;
        cin >> N >> M;
        
        if(N > M) swap(N, M);

        int res = 1, tmp = 1;
        for(int i = M; i > M - N; i--) {
            res *= i;
            res /= tmp++;
        }
        cout << res << '\n';
    }
}

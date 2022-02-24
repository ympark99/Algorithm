#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<bool> arr(N + 1, false);
    int cnt = 0;

    for(int i = 2; i <= N; i++){
        for(int j = 1; i * j <= N; j++){
            if(!arr[i * j]){
                arr[i * j] = true;
                cnt++;
            }

            if(cnt == K){
                cout << i * j << '\n';
                return 0;
            }
        }
    }
}

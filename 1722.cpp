#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long f[21];
bool check[21];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, cmd;
    cin >> N;

    f[0] = 1;

    for(int i = 1; i < 21; i++)
        f[i] = f[i - 1] * i;

    cin >> cmd;

    if(cmd == 2){
        vector<int> a(N);

        for(int i = 0; i < N; i++)
            cin >> a[i];

        long long ans = 0;

        for (int i = 0; i < N; i++){
            for (int j = 1; j < a[i]; j++){
                if(check[j] == false)
                    ans += f[N - i - 1];
            }
            check[a[i]] = true;
        }
        cout << ans + 1 << "\n";
    }
    else{
        long k;
        cin >> k;

        vector<int> a(N);

        for(int i = 0; i < N; i++){
            for(int j = 1; j <= N; j++){
                if(check[j] == true) continue;
                if(f[N - i - 1] < k){
                    k -= f[N - i - 1];
                }
                else{
                    a[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }
        for(int i = 0; i < N; i++) 
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}

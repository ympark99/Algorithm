#include <iostream>
#include <vector>

using namespace std;

int N;
long long res;

bool check[100000+1];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; i++)
        cin >> v[i];

    int end = 0;
    for(int start = 0; start < N; start++){
        while(end < N){
            if(check[v[end]])
                break;
            check[v[end]] = true;
            end++;
        }
        res += (end - start);
        check[v[start]] = 0;
    }

    cout << res << '\n';
    return 0;
}

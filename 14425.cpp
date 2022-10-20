#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    map<string, int> m;

    int cnt = 0;
    string str = "";
    for(int i = 0; i < N; i++){
        cin >> str;
        m[str] = 1;
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        if(m[str] == 1) cnt++;
    }

    cout << cnt;
    return 0;
}

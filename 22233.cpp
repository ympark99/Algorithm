#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int N, M;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    map<string, int> m;

    string str = "";
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> str;
        m[str] = 1;
        cnt++;
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        string a,b;
        bool flag = false;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == ','){
                flag = true;
                continue;
            }
            if(!flag) a += str[j];
            else b += str[j];
        }
        if(m[a] == 1){
            m.erase(a);
            cnt--;
        }
        if(m[b] == 1){
            m.erase(b);
            cnt--;
        }
        cout << cnt << '\n';
    }

    return 0;
}

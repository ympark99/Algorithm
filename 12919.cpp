#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ans = false;

void dfs(string S, string T){
    if(T == S){
        cout << 1;
        exit(0);
    }
    if(S.length() > T.length())
        return;
    if(T[T.length()-1] == 'A'){
        string str = T;
        dfs(S, str.erase(str.length()-1));
    }
    if(T[0] == 'B'){
        string str = T;
        str.erase(str.begin());
        reverse(str.begin(), str.end());
        dfs(S, str);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string S, T;
    cin >> S >> T;

    dfs(S, T);

    cout << 0;
}

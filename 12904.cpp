#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dfs(string S, string T){
    if(T == S){
        cout << 1 << '\n';
        exit(0);
    }
    if(S.length() > T.length())
        return;

    if(T[T.length()-1] == 'A'){
        string str = T;
        dfs(S, str.erase(str.length()-1));
    }

    if(T[T.length()-1] == 'B'){
        string str = T;
        str.erase(str.length()-1);
        reverse(str.begin(), str.end());
        dfs(S, str);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string S, T;
    cin >> S >> T;

    dfs(S, T);
    cout << 0 << '\n';
    return 0;
}

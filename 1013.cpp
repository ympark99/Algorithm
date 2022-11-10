#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        string str = "";
        cin >> str;

        regex pattern("(100+1+|01)+");
        if(regex_match(str, pattern))
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

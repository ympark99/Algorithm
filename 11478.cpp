#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >> str;
    int cnt = 0;

    map<string, int> m;
    for(int i = 0; i < str.length(); i++){
        for(int j = 0; j < str.length() - i; j++){
            int start = j;
            int end = j+i;
            m[str.substr(start, end - start + 1)]++;
        }
    }
    cout << m.size();
}

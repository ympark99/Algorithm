#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T, n;
    cin >> T;

    vector<string> v;
    while (T--){
        bool flag = 1;
        cin >> n;

        for(int i = 0; i < n; i++){
            string str = "";
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i <= v.size()-2; i++){
            int curLen = v[i].length();
            int nextLen = v[i+1].length();

            if(curLen >= nextLen) continue;

            if(v[i+1].substr(0, curLen) == v[i]){
                flag = 0;
                cout << "NO" << '\n';
                break;
            }
        }

        if(flag) cout << "YES" << '\n';
        
        v.clear();
    }  
}

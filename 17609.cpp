#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int isPal(int start, int end, bool isDel, string str){
    while (end > start){
        if(str[end] == str[start]){
            end--;
            start++;
        }
        else{
            if(!isDel){
                if(!isPal(start+1, end, 1, str) || !isPal(start, end-1, 1, str))
                    return 1;
                return 2;
            }
            else return 2;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    string str = "";
    while (T--){
        cin >> str;
        int res = isPal(0, str.length()-1, 0, str);
        cout << res << '\n';
    }
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int A, B; cin >> A >> B;        
    int cnt = 0;
    while (A < B){
        string str = "";
        str = to_string(B);        
        if(str[str.length()-1] == '1'){
            str = str.substr(0, str.length()-1);
            B = stoi(str);
        }
        else if(B % 2 == 1) break;
        else{
            B /= 2;
        }
        cnt++;
    }
    if(A == B) cout << cnt+1;
    else cout << -1;
}

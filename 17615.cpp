#include <iostream>
#include <string>

using namespace std;

string str;
int ans = 99999999;

void solution(char rb){
    int cnt = 0;
    bool check = false; // red, blue
    // left sort
    for(int i = 0; i < str.length(); i++){
        if(str[i] != rb)
            check = true;
        if(check && (str[i] == rb))
            cnt++;
    }
    ans = min(ans, cnt);
    check = false;
    cnt = 0;
    // right sort
    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] != rb)
            check = true;
        if(check && (str[i] == rb))
            cnt++;
    }
    ans = min(ans, cnt);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    cin >> str;

    solution('R');
    solution('B');

    cout << ans;
}

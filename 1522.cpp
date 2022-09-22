#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string str = "";
    cin >> str;
    int a = 0;
    int ans = str.size();

    for(auto c : str) 
        if(c == 'a') a++;

    for(int i = 0; i < str.size(); i++){
        int cnt = a; // 한 곳으로 몰아넣는 a 개수
        int temp = 0; // 자리 바꿀 b 개수
        for(int j = i; j < i + str.size(); j++){
            if(!cnt) break;
            if(str[j % str.size()] == 'b'){
                temp++;
                cnt--;
            }
            else cnt--;
        }
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}

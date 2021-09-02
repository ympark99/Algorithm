#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int l, p, v;
    int cnt = 1;
    string answer = "";

    while(1){
        answer += "Case ";
        answer += to_string(cnt);
        answer += ": ";

        cin >> l >> p >> v;

        if(l == 0 && p == 0 && v == 0) return 0;

        int day1 = l * (v / p);
        int day2 = min(l, v % p);

        answer += to_string(day1 + day2);
        
        cout << answer << '\n';

        answer.clear();

        cnt++;
    }

    return 0;
}

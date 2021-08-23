#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MN = 4001;

int dp[MN][MN] = {0,};

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s1, s2;

    cin >> s1 >> s2;

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    int answer = 0;
    for(int i = 1; i < s1.length(); i++){
        for(int j = 1; j < s2.length(); j++){
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

/*
    for(int i = 1; i < s1.length(); i++){
        for(int j = 1; j < s2.length(); j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }    
*/
    cout << answer;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MN = 1001;

int dp[MN][MN];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    s1 = ' ' + s1;
    s2 = ' ' + s2;    

    for(int i = 1; i < s1.length(); i++){
        for(int j = 1; j < s2.length(); j++){
            if(s1[i] == s2[j]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[s1.length()-1][s2.length()-1];
    return 0;
}

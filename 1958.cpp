#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MN = 101;

int dp[MN][MN][MN] = {0,};

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;


    for(int i = 1; i < s1.length(); i++){
        for(int j = 1; j < s2.length(); j++){
            for(int k = 1; k < s3.length(); k++){
                if(s1[i] == s2[j] && s2[j] == s3[k])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]), dp[i][j][k-1]);
            }
        }
    }

    cout << dp[s1.length()-1][s2.length()-1][s3.length()-1];

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int notArr[2] = {0,};

void notMe(int rgb){
    int num = 0;
    for(int i=0; i<2; i++){
        if(num == rgb) num++;
        notArr[i] = num++;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[MAX][3] = {0,};
    int dp[MAX][3] = {0,};

    int n;
    int res = 1000 * MAX ;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }


    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            notMe(j);
            dp[i][j] = arr[i][j] + min(dp[i-1][notArr[0]],dp[i-1][notArr[1]]);        
        }
    }


    for(int i=0; i<3; i++){
        res = min(res, dp[n-1][i]);
    }
    cout << res;

    return 0;
}

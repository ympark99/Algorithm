#include <iostream>
#define MAX 21
 
using namespace std;
 
int dp[MAX][MAX][MAX];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return w(20,20,20);

    int &result = dp[a][b][c];
    if(result != 0) return result;


    if(a < b && b < c) result = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else result = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a,b,c;

    while(1){
        cin >> a >> b >> c;
        if (a == -1 && b== -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n",a, b, c, w(a,b,c));
    }    

    return 0;
}

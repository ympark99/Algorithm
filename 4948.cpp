#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 123456 * 2;

int main(){
    bool check[MAX * 2] = {false, };
    check[0] = true; check[1] = true;

    for(int i = 2; i <= sqrt(MAX); i++){
        if(check[i]) continue;
        for(int j = i * 2; j <= MAX; j += i)
            check[j] = true;
    }

    while (1)
    {
        int n;
        cin >> n;
        int cnt = 0;

        if(n == 0) return 0;
        for(int i = n + 1; i <= 2 * n; i++)
            if(!check[i]) cnt++;

        cout << cnt << '\n';        
    }   
    return 0;
}

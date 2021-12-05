#include <iostream>

using namespace std;

int self(int n){
    int sum = n;

    while(1){
        if(n == 0) break;
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    bool check[10000 + 1] = {false, };

    for(int i = 1; i <= 10000; i++){
        int num = self(i);

        if(num <= 10000) check[num] = true;
    }

    for(int i = 1; i <= 10000; i++){
        if(!check[i]) cout << i << '\n';
    }

    return 0;
}

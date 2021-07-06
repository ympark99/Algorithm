#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long a,b;
    int answer = 0;
    cin >> a >> b;

    int * check = new int[b + 1] {0,};
    check[0] = 1; check[1] = 1;

    for(long i = 2; i <= sqrt(b); i++){
        if(check[i]) continue;
        for(long j = i * 2; j <= b; j += i)
            check[j] = 1;

        for(long j = i * i; j <= b; j *= i)
            check[j] = 2;                    
    }

    for(long i = a; i <= b; i++){
        if(check[i] == 2) answer++;
    }

    cout << answer;

    return 0;
}

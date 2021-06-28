#include <iostream>

using namespace std;

int main(void){
    long long N,P;
    cin >> N >> P;
    long long fac = 1;
    for(long long i = 1; i <= N; i++){
        fac *= i;
        fac %= P;
    }
    cout << fac;
}

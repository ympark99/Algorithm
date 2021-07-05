#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b? gcd(b , a % b) : a;
}

int main(){
    int a1, b1, a2, b2, son, mom;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    son = a1 * b2 + a2 * b1;
    mom = b1 * b2;

    int gcd_num = gcd(mom, son);
    if(gcd_num == 1){
        cout << son << " " << mom;
    }
    else{
        cout << son / gcd_num << " " << mom / gcd_num;
    }

    return 0;
}

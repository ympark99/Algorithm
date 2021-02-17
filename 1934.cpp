#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int main(void){
    cin.tie(0);

    int n;
    cin >> n;


    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;

        cout << lcm(a,b) << "\n";
    }
}

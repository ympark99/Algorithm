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
}

int main(void){
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

}

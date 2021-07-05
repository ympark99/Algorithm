#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    if(num == 1) return 0;

    int i = 2;
    while(i <= num){
        if(num == 1){
            break;
        }
        if(num % i == 0){
            cout << i << '\n';
            num /= i;
            i = 2;
            continue;
        }
        i++;
    }
    return 0;
}

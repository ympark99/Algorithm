#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long S; cin >> S;
    int num = 1;
    int cnt = 0;
    long long sum = 0;

    while (1){
        sum += num;
        cnt++;
        if(sum > S){
            cnt--;
            break;
        }
        num++;
    }
    cout << cnt << '\n';
    return 0;
}

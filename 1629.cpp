#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c;

long long solution(long long b){
    if(b == 0) return 1;
    if(b == 1) return a % c;

    long long half = solution(b / 2) % c;

    if(b % 2 == 0) return half * half % c;
    return half * half % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << solution(b);
}

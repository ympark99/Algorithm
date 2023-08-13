#include <bits/stdc++.h>
 
using namespace std;

int n;
int ans;

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    cin >> n;

    int start = n / 5;
    int remain = (n - start * 5) % 2;
    while(remain) {
        if(!start) {
            cout << -1;
            return 0;
        }
        start--;
        remain = (n - start * 5) % 2;
    }

    cout << start + (n - start * 5) / 2;

    return 0;
}

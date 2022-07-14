#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i *= 10)
        ans += n - i + 1;
    cout << ans;
    return 0;
}

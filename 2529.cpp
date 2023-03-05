#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k;
char c[10];
bool check[10];
vector<string> ans;
bool ok(string num) {
    for (int i = 0; i < k; i++) {
        if (c[i] == '>') {
            if (num[i] < num[i + 1]) return false;
        }
        else if (c[i] == '<') {
            if (num[i] > num[i + 1]) return false;
        }
         
    }
    return true;
}
void go(int index, string num) {
    if (index == k + 1) {
        if (ok(num)) ans.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue;
        check[i] = true;
        go(index + 1, num+to_string(i));
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) cin >> c[i];
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << "\n";
    cout << *p.first;
}

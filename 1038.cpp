#include <bits/stdc++.h>
 
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    cin >> N;

    vector<long long> v;
    queue<long long> q;
    for(int i = 0; i <= 9; i++) {
        q.push(i);
        v.push_back(i);
    }

    while(!q.empty()) {
        long long num = q.front();
        int last = num % 10;
        q.pop();
        for(int i = 0; i < last; i++) {
            long long next = num * 10 + i;
            q.push(next);
            v.push_back(next);
        }
    }
    if(N >= v.size())
        cout << -1;
    else cout << v[N];

    return 0;
}

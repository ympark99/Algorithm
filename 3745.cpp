#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, x;
    // cin >> n;

    vector<int> v;
    while (cin >> n)
    {
        for(int i = 0; i < n; i++){
            cin >> x;
            if(v.empty() || v.back() < x) v.push_back(x);
            else{
                auto iter = lower_bound(v.begin(), v.end(), x);
                *iter = x;
            }
        }
        cout << int(v.size()) << '\n';
        v.clear();
    }

    return 0;
}

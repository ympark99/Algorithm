#include <bits/stdc++.h>

using namespace std;

string s, p;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s >> p;
    int cnt = 0;
    for(int i = 0; i < p.length();){
        int max_len = 0;
        for(int j = 0; j < s.length(); j++){
            int tmp = 0;
            while(s[j+tmp] == p[i+tmp])
                tmp++;
            max_len = max(max_len, tmp);
        }
        i += max_len;
        cnt++;
    }
    cout << cnt << '\n';
	return 0;
}

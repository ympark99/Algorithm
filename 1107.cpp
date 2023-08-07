#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bool> broken(10, false);

bool check(int now){
    string s = to_string(now);
    for(int i = 0; i < s.length();i++){
        if(broken[s[i]-'0']){
            return false;
        }
    }
    return true;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}

    int ans = abs(N-100);
    for(int i = 0; i <= 1000000; i++){
        if(check(i)) {
            int tmp = abs(N-i) + to_string(i).length();
            ans = min(ans, tmp);
        }
    }

	cout << ans << '\n';

	return 0;
}

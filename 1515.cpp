#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str = "";
	cin >> str;

	int base = 0;
	int ptr = 0;

	while(base++ < 30000) {
		string tmp = to_string(base);
		for(int i = 0; i < tmp.length(); i++) {
			if(str[ptr] == tmp[i]) {
				ptr++;
			}
			if(ptr == str.length()) {
				cout << base;
				return 0;
			}
		}
	}
	return 0;
}

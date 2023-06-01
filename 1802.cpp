#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;

bool dc(string str, int startIdx, int endIdx){
	if(startIdx > endIdx)
		return true;

	int left = startIdx;
	int right = endIdx;

	while(left < right) {
		if(str[left++] == str[right--])
			return false;
	}
	return dc(str, startIdx, right - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while(T--) {
		string str = "";
		cin >> str;

		if(str.length() % 2 == 0){
			cout << "NO" << '\n';
			return 0;
		}

		cout << (dc(str, 0, str.length() - 1) ? "YES\n" : "NO\n");
	}
	return 0;
}

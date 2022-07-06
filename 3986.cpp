#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string words[101];

	for (int i = 0; i < N; ++i) {
		cin >> words[i];
	}

	int goodNum = 0;

	for (int i = 0; i < N; ++i) {
		stack<char> stk;
		for (int j = 0; j < words[i].length(); ++j) {
			if (stk.empty()) {
				stk.push(words[i][j]);
			}
			else if (stk.top() == words[i][j]) {
				stk.pop();
			}
			else if (stk.top() != words[i][j]) {
				stk.push(words[i][j]);
			}
		}
		if (stk.empty()) {
			++goodNum;
		}
	}

	cout << goodNum;

	return 0;
}

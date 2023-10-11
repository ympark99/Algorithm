#include <bits/stdc++.h>

using namespace std;

int primes[4] = {2, 3, 5, 7};
int N;

bool isPrime(string str) {
	int num = stoi(str);
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0)
			return false;
	}
	return true;
}

void dfs(string str) {
	if(str.length() == N) {
		cout << str << '\n';
		return;
	}

	for(int i = 1; i <= 9; i++) {
		str += to_string(i);
		if(isPrime(str)) {
			dfs(str);
		}
		str.pop_back();
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < 4; i++) {
		string str = "";
		str += to_string(primes[i]);
		dfs(str);
	}

	return 0;
}

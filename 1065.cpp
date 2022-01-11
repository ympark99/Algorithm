#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	if(N < 100) cout << N;
	else if(N == 1000) cout << 144;
	else{
		int cnt = 99;
		int a, b, c = 0;
		for(int i = 100; i <= N; i++){
			a = i % 10;
			b = (i / 10) % 10;
			c = (i / 100) % 10;
			if(c - b == b - a) cnt++;		
		}

		cout << cnt;
	}

	return 0;
}

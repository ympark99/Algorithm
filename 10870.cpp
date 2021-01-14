#include <iostream>

using namespace std;

int fibo(int n){
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return fibo(n-1) + fibo(n-2);
}

int main(void) {
    cin.tie(0);
    cin.sync_with_stdio(0);

	int n;
	int res;
	cin >> n;

	res = fibo(n);
	cout << res << endl;

	return 0;
}

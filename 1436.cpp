#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int n;
	int cnt = 0;
	int res = 665;
	string s;
 
	cin >> n;
 
	while(++res){
		s = to_string(res);
 
		if (s.find("666") != -1) {
			++cnt;
		}
 
		if (cnt == n) {
			cout << res << endl;
			break;
		}
	}
 
	return 0;
}

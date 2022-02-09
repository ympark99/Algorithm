#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	string str = "";
	cin >> str;

	string add = "??!";

	str += add;

	cout << str;

	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string str;
	cin >> str;

	sort(str.begin(), str.end(), greater<char>());

	long long sum = 0;
	for(int i = 0; i < str.length(); i++)
		sum += str[i] - '0';

	bool go_next = false;
	if(sum % 3 == 0){
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '0'){
				go_next = true;
				break;
			}
		}
	}
	if(!go_next){
		cout << -1;
		return 0;
	}	
	else cout << stoi(str);
}

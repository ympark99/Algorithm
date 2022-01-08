#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	if(N < 9) cout << N + 1;
	else if(N == 9) cout << 11;
	else{
		string str = to_string(N);

		int midIdx = 0;
		if(N % 2 != 0) midIdx = str.length() / 2 + 1;
		else midIdx = str.length() / 2;

		string afterPalin = str;
		string palin = str.substr(0, midIdx);
		reverse(palin.begin(), palin.end());
		afterPalin.replace(afterPalin.length() - palin.length(), palin.length(), palin);
		
		if(afterPalin > str){
			cout << afterPalin;
			return 0;
		}
		else{
			// 9로만 이루어졌는지 확인
			string palin2 = str.substr(0, midIdx);
			string isNine(palin2.length(), '9');
			if(isNine == palin2){
				string toZero(str.length() - 1, '0');
				toZero = '1' + toZero + '1';
				cout << toZero;
				return 0;
			}

			palin2 = to_string(stoi(palin2) + 1);
			str.replace(0, palin2.length(), palin2);
			reverse(palin2.begin(), palin2.end());
			str.replace(str.length() - palin2.length(), palin2.length(), palin2);
			cout << str;
		}
	}

	return 0;
} 

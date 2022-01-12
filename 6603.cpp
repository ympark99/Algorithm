#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	while(1){
		/*
		string str;
		vector<string> v;
		while(getline(cin, str, ' ')){
			v.push_back(str);
		}
		
		// if(v[0] == "0") break;
		if(str.length() == 1 && str[0] == '0') break;	

		int k = str[0] - '0';

		// 공백 제거
		// str.erase(remove(str.begin(), str.end(), ' '), str.end());			

		// for(int i = 1; i < str.length(); i++)
		// 	v.push_back(str[i]);

		*/

		int k; cin >> k;
		if(k == 0) break;

		vector<int> v(k);
		for(int i = 0; i < k; i++)
			cin >> v[i];

		vector<bool> lotto(k, true);

		// nCr 구현
		// true가 false 뒤에 와야함
		for(int i = 0; i < 6; i++)
			lotto[i] = false;		
		
		do{
			for(int i = 0; i < v.size(); i++){
				if(!lotto[i]) cout << v[i] << ' ';
			}
			cout << '\n';
		}while(next_permutation(lotto.begin(), lotto.end()));
			
		cout << '\n';
	}

	return 0;
}

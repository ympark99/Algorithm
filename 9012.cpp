#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		stack<char> st;
		char ch;
		bool isNo = false;

		for(int j=0; j<str.size(); j++){
			if(str[j] == ')'){
				if(st.empty()){
					isNo = true;
					break;
				}
				else st.pop();
			}else st.push(str[j]);
		}
		if(isNo) cout << "NO" << endl;
		else if(!st.empty()) cout << "NO" << endl;
		else cout << "YES" << endl;
	}


	return 0;
}

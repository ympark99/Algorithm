#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	string str;
	int cnt = 1;
	while(1){
		cin >> str;
		if(str.empty() || str[0] == '-') break;

		stack<char> st;
		int answer = 0;
		string output = "";

		for(auto elem : str){
			if(elem == '}' && st.top() == '{' && !st.empty()) st.pop();
			else st.push(elem);
		}

		while(!st.empty()){
			if(st.top() == '}'){
				answer += st.size() / 2;
				break;
			}
			else{
				st.pop();
				if(st.top() == '{') answer++;
				else answer += 2;
				st.pop();
			}
		}	
		
		output += to_string(cnt);
		output += ". ";
		output += to_string(answer);

		cout << output << '\n';

		cnt++;		
	}

	return 0;
} 

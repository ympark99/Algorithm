#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int main() {
	while (1) {
		string Text;
		getline(cin, Text);
		
		if (Text.size() == 1 && Text[0] == '.') break;
		bool check_Line = false;
		stack <char> st;
		for (int i = 0; i < Text.size(); i++) {
			if (Text[i] == '(' || Text[i] == '[')
				st.push(Text[i]);
			else if (Text[i] == ')') {
				if (st.size() > 0 && st.top() == '(')
					st.pop();
				else {
					check_Line = true;
					break;
				}
			}
			else if (Text[i] == ']') {				
				if (st.size() > 0 && st.top() == '[')
					st.pop();
				else {
					check_Line = true;
					break;
				}
			}
		}

		if (st.empty() && !check_Line)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

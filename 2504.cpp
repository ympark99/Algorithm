#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
string str;
stack<char> s;
 
int main(void) {
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    cin >> str;
 
    int answer = 0, tmp = 1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            tmp *= 2;
            s.push('(');
        }
        else if(str[i] == '[') {
            tmp *= 3;
            s.push('[');
        }
        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                answer = 0;
                break;
            }
            if(str[i-1] == '(') {
                answer += tmp;
                tmp /= 2;
                s.pop();
            }
            else {
                tmp /= 2;
                s.pop();
            }
        }
        else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {   //올바르지 못한 괄호열
                answer = 0;
                break;
            }
            if(str[i-1] == '[') {
                answer += tmp;
                tmp /= 3;
                s.pop();
            }
            else {
                tmp /= 3;
                s.pop();
            }
        }
    }
 
    if(!s.empty()) answer = 0;
 
    cout << answer << "\n";
 
    return 0;
}

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) { 
    string answer = "";
    int size = number.length() - k;
    stack<char> st;
    
    for(int i = 0; i < number.length(); i++){
        char cur = number.at(i); 
        while(!st.empty() && k > 0){ //
            char top = st.top();
            if(top < cur){ 
                st.pop(); 
                k--; 
            }
            else break; 
        } 
        st.push(cur); 
    }    
    
    while(st.size() != size) st.pop(); 
    
    while(!st.empty()){ 
        answer += st.top();
        st.pop();
    }    
    
    reverse(answer.begin(), answer.end()); 
    
    return answer;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());

    stack<pair<int, int>> st;
    
    for(int i = 0; i < numbers.size(); i++) {
        int now = numbers[i];
        
        while(!st.empty()) {
            if(st.top().first < now) {
                answer[st.top().second] = now;
                st.pop();
            }
            else break;
        }
        st.push({now, i});
    }
    
    while(!st.empty()) {
        answer[st.top().second] = -1;
        st.pop();
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    for(int i=0; i<prices.size()-1; i++){
        answer.push_back(0);
        if(prices[i] <= prices[i+1]){
            st.push(make_pair(i,prices[i]));
        }
        else{
            answer[i] = 1;
            while (!st.empty())
            {
                if(st.top().second > prices[i+1]){
                    answer[st.top().first] = (i+1) - st.top().first;
                    st.pop();
                }
                else break;
            }            
        }
    }
    answer.push_back(0);
    st.push(make_pair(prices.size(),prices[prices.size()]));
    while (!st.empty())
    {
        answer[st.top().first] = prices.size() - (st.top().first + 1);
        st.pop();
    }    
    return answer;
}

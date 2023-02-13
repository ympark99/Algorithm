#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int box = 0;
    stack<int> go, back;
    
    for(auto elem : deliveries)
        go.push(elem);
    
    for(auto elem : pickups)
        back.push(elem);
    
    // 가장 먼 집이 택배나 회수할게 없으면 안됨
    while(!go.empty() && !go.top())
        go.pop();
    while(!back.empty() && !back.top())
        back.pop();
    

    while(!(go.empty() && back.empty())){
        answer += max(go.size() * 2, back.size() * 2);
        
        box = 0;
        while(!go.empty() && box <= cap){
            if(go.top() + box <= cap)
                box += go.top();
            else{
                go.top() -= (cap - box);
                break;
            }
            go.pop();
        }
        box = 0;        
        while(!back.empty() && box <= cap){
            if(back.top() + box <= cap)
                box += back.top();
            else{
                back.top() -= (cap - box);
                break;
            }
            back.pop();
        }        
    }        
    return answer;
}

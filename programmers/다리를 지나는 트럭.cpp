#include <bits/stdc++.h>

using namespace std;

int idx, sum;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    
    while(1) {
        if(idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        answer++;
        int now_weight = truck_weights[idx];
        
        if(q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }
        
        if(sum + now_weight <= weight) {
            q.push(now_weight);
            sum += now_weight;
            idx++;
        }
        else {
            q.push(0);
        }        
    }
    
    return answer;
}

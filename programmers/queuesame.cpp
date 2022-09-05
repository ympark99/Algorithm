#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> q1;
queue<int> q2;
long sum1, sum2, target, cnt;
long ans = 99999999;

void get_ans(){
    while(!q1.empty() && !q2.empty()){
        if((sum1 == target) && (sum2 == target)){
            ans = min(ans, cnt);
            return;
        }        
        if(sum1 > target){
            int tmp = q1.front();
            sum2 += tmp;
            sum1 -= tmp;
            q2.push(tmp);
            q1.pop();
            cnt++;
        }
        else if(sum2 > target){
            int tmp = q2.front();
            sum1 += tmp;
            sum2 -= tmp;
            q1.push(tmp);
            q2.pop(); 
            cnt++;
        }
    }    
    ans = -1;
    return;
}

long solution(vector<int> queue1, vector<int> queue2) {
    long answer = -2;
    
    for(auto elem : queue1){
        q1.push(elem);
        sum1 += elem;
    }
    for(auto elem : queue2){
        q2.push(elem);
        sum2 += elem;
    }
    if(((sum1 + sum2) % 2) == 1)
        return -1;
    
    target = (sum1 + sum2) / 2;
    
    get_ans();
    
    answer = ans;
    return answer;
}

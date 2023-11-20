#include <queue>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
        sum += i;
        if(sum == n) {
            answer++;
        }
        else if(sum > n) {
            while(!q.empty()) {
                sum -= q.front();
                q.pop();
                if(sum == n) answer++;
                if(sum <= n) break;
            }
        }
    }
    
    return answer;
}

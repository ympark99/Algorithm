#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto elem : scoville){
        pq.push(elem);
    }
    while(K > pq.top() && !pq.empty()){
        int first = pq.top();
        answer++;
        pq.pop();
        if(pq.empty()) return -1;
        int second = pq.top();
        int mix = first + second * 2;
        pq.push(mix);
        pq.pop();
    }
    return answer;
}

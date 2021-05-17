#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> spend(progresses.size());
    queue<int> q;
    int cnt = 1;

    for(int i=0; i<progresses.size(); i++){
        if((100-progresses[i]) % speeds[i] == 0) spend.push_back((100-progresses[i]) / speeds[i]);
        else spend.push_back((100-progresses[i]) / speeds[i] + 1);
        q.push(spend.back());
    }

    int front = q.front();
    while(!q.empty()){
        q.pop();
        if(q.front() > front){
            front = q.front();
            answer.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    if(cnt != 1) answer.push_back(cnt-1);
    return answer;
}

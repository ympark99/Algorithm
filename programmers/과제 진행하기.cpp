#include <bits/stdc++.h>

using namespace std;

typedef struct _node{
    string name;
    int start;
    int takes;
} node;

node arr[1001];
stack<node> s;

bool cmp(node a, node b){
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int idx = 0;
    int N = plans.size();
    for(int i = 0 ; i < N; i++){
        arr[i].name = plans[i][0];
        arr[i].takes = stoi(plans[i][2]) * 1;
        arr[i].start = (plans[i][1][0]- '0') * 600
                        + (plans[i][1][1] - '0') * 60
                        + (plans[i][1][3] - '0') * 10
                        + (plans[i][1][4] - '0');
    }
    sort(arr,arr+N,cmp);
    node cur;
    node next = arr[idx++];
    while(idx < N){
        cur = next;
        next = arr[idx++];
        int diff = next.start - cur.start;
        if(diff >= cur.takes){
            diff -= cur.takes;
            answer.push_back(cur.name);
            while(diff > 0 && !s.empty()){
                node snode = s.top(); s.pop();
                if(diff >= snode.takes){
                    diff -= snode.takes;
                    answer.push_back(snode.name);
                }
                else{
                    snode.takes -= diff;
                    diff = 0;
                    s.push(snode);
                }
            }
        }
        else{
            cur.takes -= diff;
            s.push(cur);
        }
    }
    answer.push_back(arr[N-1].name);
    while(!s.empty()){
        cur = s.top(); s.pop();
        answer.push_back(cur.name);
    }
    return answer;
}

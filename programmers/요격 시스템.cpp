#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), comp);
    
    int now = targets[0][1];
    for(int i = 1; i < targets.size(); i++) {
        if(targets[i][0] >= now) {
            answer++;
            now = targets[i][1];
        }
        else now = min(now, targets[i][1]);
    }
    
    return answer;
}

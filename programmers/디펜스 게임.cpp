#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

void use_coupon(int &n, int &k, vector<int> &enemy) { 
    k--;
    if(!pq.empty()) {
        n += pq.top();
        pq.pop();
    }
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    for(int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        if(n < 0) {
            if(k == 0) break;
            use_coupon(n, k, enemy);
        }
        answer++;
    }
    
    return answer;
}

#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void dfs(int idx, vector<int> cards, vector<bool> &check, int cnt) {
    check[idx] = true;
    int nextIdx = cards[idx] - 1;
    
    if(check[nextIdx]) {
        v.push_back(cnt);
        return;
    }
    else {
        dfs(nextIdx, cards, check, cnt+1);
    }
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<bool> check(cards.size());
    
    for(int i = 0; i < cards.size(); i++) {
        if(!check[i]) {
            dfs(i, cards, check, 1);
        }
    }
    if(v.size() <= 1) return 0;
    
    sort(v.begin(), v.end(), greater<>());
    answer = v[0] * v[1];
    
    return answer;
}

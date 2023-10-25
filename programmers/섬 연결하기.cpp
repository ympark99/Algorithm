#include <bits/stdc++.h>

using namespace std;

vector<int> edge(100); // to, cost

int findParent(int x) {
    if(edge[x] == x)
        return x;
    return edge[x] = findParent(edge[x]);
}

bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
        edge[i] = i;
    
    sort(costs.begin(), costs.end(), comp);
    
    for(int i = 0; i < costs.size(); i++) {
        int from = findParent(costs[i][0]);
        int to = findParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(from != to) {
            answer += cost;
            edge[to] = from;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(int i = 0; i < tangerine.size(); i++) {
        int num = tangerine[i];
        m[num]++;
    }
    vector<int> v;
    for(auto elem : m)
        v.push_back(elem.second);
    
    sort(v.begin(), v.end(), greater<int>());
    
    int cnt = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(cnt >= k) break;
        answer++;
        cnt += v[i];
    }
        
    return answer;
}

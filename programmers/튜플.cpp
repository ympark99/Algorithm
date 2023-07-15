#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    string tmp;
    for (int i = 1; i < s.length() - 1; i++){
      if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
        tmp += s[i];
        if (s[i+1] != ',' && s[i+1] != '}') continue;
        m[stoi(tmp)]++;
      }
      tmp = "";
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    
    for(auto elem: v)
        answer.push_back(elem.first);
    
    return answer;
}

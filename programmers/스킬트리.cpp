#include <bits/stdc++.h>

using namespace std;

int alpha[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0; i < skill.length(); i++)
        alpha[skill[i] - 'A'] = i + 1;
    
    for(int i = 0; i < skill_trees.size(); i++) {
        string str = skill_trees[i];
        bool flag = false;
        int idx = 1;
        for(int j = 0; j < str.length(); j++) {
            if(alpha[str[j] - 'A'] == idx) {
                idx++;
                continue;
            }
            else if(alpha[str[j] - 'A'] == 0)
                continue;
            else if(alpha[str[j] - 'A'] > idx) {
                flag = true;
                break;
            }
        }
        if(!flag)
            answer++;   
    }
    
    return answer;
}

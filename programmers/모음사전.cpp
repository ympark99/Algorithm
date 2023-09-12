#include <string>
#include <vector>

using namespace std;

string target = "";
string lists = "AEIOU";
int answer = -1;
int cnt = -1;

void dfs(string now) {
    cnt++;
    if(now == target) {
        answer = cnt;
        return;
    }
    
    if(now.length() >= 5) return;
    
    for(int i = 0; i < 5; i++) {
        dfs(now + lists[i]);
    }
}

int solution(string word) {    
    target = word;
    dfs("");
    return answer;
}

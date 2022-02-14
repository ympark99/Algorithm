#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 51;

void dfs(string now, string target, vector<string> words, int cnt, vector<bool>& check){
    if(now == target){
        answer = min(answer, cnt);
        return;
    }

    for(int i = 0; i < words.size(); i++){
        int dif = 0;
        for(int j = 0; j < words[i].length(); j++){
            if(!check[i] && words[i][j] != now[j]) dif++;
        }
        
        if(dif == 1){
            check[i] = true;
            dfs(words[i], target, words, cnt + 1, check);
            check[i] = false;
        }
    }

    return;
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> check(words.size(), false);

    if(find(words.begin(), words.end(), target) == words.end())
        return 0;

    dfs(begin, target, words, 0, check);
//     bfs(begin, target, words, 0, check);    

    if(answer == 51) return 0;

    return answer;
}

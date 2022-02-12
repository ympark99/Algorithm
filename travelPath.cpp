#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void dfs(vector<vector<string>> tickets, vector<bool>& check, string now, int cnt){
    if(tickets.size() == cnt){
        answer.push_back(now);
        return;
    }

    for(int i = 0; i < tickets.size(); i++){
        if(!check[i] && tickets[i][0] == now){
            check[i] = true;
            answer.push_back(tickets[i][0]);
            dfs(tickets, check, tickets[i][1], cnt + 1);
            check[i] = false;
            break;
        }        
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> check(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    dfs(tickets, check, "ICN", 0);

    return answer;
}

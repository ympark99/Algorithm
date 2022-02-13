// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<string> answer;

// void dfs(vector<vector<string>> tickets, vector<bool>& check, string now, int cnt){
//     if(tickets.size() == cnt){
//         answer.push_back(now);
//         return;
//     }

//     for(int i = 0; i < tickets.size(); i++){
//         if(!check[i] && tickets[i][0] == now){
//             check[i] = true;
//             answer.push_back(tickets[i][0]);
//             dfs(tickets, check, tickets[i][1], cnt + 1);
//             check[i] = false;
//             break;
//         }        
//     }
// }

// vector<string> solution(vector<vector<string>> tickets) {
//     vector<bool> check(tickets.size(), false);

//     sort(tickets.begin(), tickets.end());

//     dfs(tickets, check, "ICN", 0);

//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {
    temp.push_back(start);
    
    if (max_cnt < cnt) {
        max_cnt = cnt;
        answer = temp;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (start == tickets[i][0] && !visit[i]) {
            visit[i] = true;
            DFS(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
            visit[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    int cnt = 0;
    vector<string> answer, temp;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, visit, answer, temp, cnt);
    return answer;
}

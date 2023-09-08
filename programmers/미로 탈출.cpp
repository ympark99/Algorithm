#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct maze {
    int row;
    int col;
    int cost;
};

pair<int, int> start;
pair<int, int> lever;
pair<int, int> exits;
bool check[101][101];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<string> maps, pair<int, int> start, pair<int, int> target) { 
    queue<maze> q;
    q.push({start.first, start.second, 0});
    
    while(!q.empty()) {
        int row = q.front().row;
        int col = q.front().col;
        int cost = q.front().cost;
        check[row][col] = true;
        q.pop();
        
        if(row == target.first && col == target.second) {
            ans += cost;
            return 0;
        }
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + dy[i];
            int ncol = col + dx[i];
            
            if(nrow < 0 || nrow >= maps.size() || ncol < 0 || ncol >= maps[0].length())
                continue;
            
            if(check[nrow][ncol] || maps[nrow][ncol] == 'X')
                continue;
            check[nrow][ncol] = true;
            q.push({nrow, ncol, cost+1});       
        }   
    }
    return -1;
}

int solution(vector<string> maps) {
   
    for(int i = 0; i < maps.size(); i++) {
        string str = maps[i];
        for(int j = 0; j < str.length(); j++) {
            if(str[j] == 'S')
                start = {i, j};
            else if(str[j] == 'L')
                lever = {i, j};
            else if(str[j] == 'E')
                exits = {i, j};
        }
    }
    
    if(bfs(maps, start, lever) == -1) {
        return -1;
    }
    memset(check, false, sizeof(check));
    if(bfs(maps, lever, exits) == -1) {
        ans = -1;
    }
    return ans;
}

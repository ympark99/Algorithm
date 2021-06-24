#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum = 0;
int answer = 0;
bool visited[500][500] = {0,};

void dfs(int column, int row, int height, vector<vector<int>> triangle){
   sum += triangle[column][row];
   visited[column][row] = 1;

   if(height == column + 1){
      answer = max(sum, answer);
      sum -= triangle[column][row];
      return;
   }

   if(visited[column + 1][row] == 0) dfs(column + 1, row, height, triangle);
   if(visited[column + 1][row] == 1) dfs(column + 1, row + 1, height, triangle);

   sum -= triangle[column][row];
   return;
}

int solution(vector<vector<int>> triangle) {
   dfs(0, 0, triangle.size(), triangle);
   return answer;
}

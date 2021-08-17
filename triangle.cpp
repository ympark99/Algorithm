#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    dp[0][0] = triangle[0][0];

    for(int i = 1; i < triangle.size(); i++){
        int end = triangle[i].size();
        for(int j = 0; j < end; j++){
            if(j == 0 || j == end) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    for(int i = 0; i < triangle.size(); i++){
        answer = max(answer, dp[triangle.size() - 1][i]);
    }

    return answer;
}

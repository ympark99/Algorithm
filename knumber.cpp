#include <vector>
#include <algorithm>

using namespace std;
 
vector<int> solution(vector<int> array1, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++){
        vector<int> cut;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            cut.push_back(array1[j]);
        sort(cut.begin(), cut.end());
        answer.push_back(cut.at(commands[i][2] - 1));
    }
    return answer;
}

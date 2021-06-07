#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int>::iterator iter;
    int num = 0;
    int zero = 0;
    vector<int> rank = {6,6,5,4,3,2,1};

    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0){
             zero++;
             continue;
        }
        iter = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if(iter != win_nums.end()) num++;
    }
    answer.push_back(rank[num + zero]);
    answer.push_back(rank[num]);
    return answer;
}

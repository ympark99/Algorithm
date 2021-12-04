#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    map<string, int>::iterator iter;

    for(int i = 0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }    
    for(iter = m.begin(); iter != m.end(); iter++){
        answer *= (iter->second + 1);
    }
    return answer - 1;
}

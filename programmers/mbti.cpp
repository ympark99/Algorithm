#include <string>
#include <vector>
#include <map>

using namespace std;

int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    for(int i = 0; i < survey.size(); i++){
        if(choices[i] == 4) continue;
        else if(choices[i] < 4){
            m[survey[i][0]] += score[choices[i]];
        }
        else 
             m[survey[i][1]] += score[choices[i]];
    }
    
    if(m['T'] > m['R']) answer += "T";
    else answer += "R";
    
    if(m['F'] > m['C']) answer += "F";
    else answer += "C";
    
    if(m['M'] > m['J']) answer += "M";
    else answer += "J";
    
    if(m['N'] > m['A']) answer += "N";
    else answer += "A";    
    
    
    return answer;
}

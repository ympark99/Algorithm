#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    // 단위 개수
    for(int i = 1; i <= s.length() / 2; i++){
        int cnt = 1; // 같은 쌍 개수
        string temp = "", a = "";
        a = s.substr(0, i);
        for(int j = i; j < s.length(); j+= i){
            if(s.substr(j, i) == a)
                cnt++;
            else{
                if(cnt > 1)
                    temp += to_string(cnt);
                temp += a;
                a = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt > 1)
            temp += to_string(cnt);
        temp += a;
        answer = min(answer, (int)temp.length());        
    }        
    return answer;
}

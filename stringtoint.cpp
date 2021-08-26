#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            answer += s[i];
        }
        else{
            if(s[i] == 'z'){
                answer += '0';
                i += 3;
            }
            else if(s[i] == 'o'){
                answer += '1';
                i += 2;
            }
            else if(s[i] == 't'){
                if(s.substr(i, 3) == "two"){
                    answer += '2';
                    i += 2;
                }
                else{
                    answer += '3';
                    i += 4;
                }
            }
            else if(s[i] == 'f'){
                if(s.substr(i, 4) == "four"){
                    answer += '4';
                }
                else{
                    answer += '5';
                }
                i += 3;
            }
            else if(s[i] == 's'){
                if(s.substr(i, 3) == "six"){
                    answer += '6';
                    i += 2;
                }
                else{
                    answer += '7';
                    i += 4;
                }
            }
            else if(s[i] == 'e'){
                answer += '8';
                i += 4;
            }
            else if(s[i] == 'n'){
                answer += '9';
                i += 3;
            }
        }
    }
    
    return stoi(answer);
}

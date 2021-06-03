#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score = 0;
    int prev = 0;
    for(int i = 0; i < dartResult.length(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            prev = score;            
            if(dartResult[i + 1] == '0'){
                score = 10;
                i++;
            }
            else score = dartResult[i] - '0';
        }
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if(dartResult[i] == 'D') score =  pow(score,2);
            else if(dartResult[i] == 'T') score = pow(score,3);

            if(dartResult[i+1] == '*'){
                answer -= prev;
                prev *= 2;
                score *= 2;
                answer += prev;
                i++;
            }
            else if(dartResult[i+1] == '#'){
                score *= -1;
                i++;
            }
            answer += score;
        }
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= yellow; i++){
        if( i < yellow / i || yellow % i != 0){
            continue;
        }
        int td = (i + 2) * 2;
        int lr = (yellow / i) * 2;
        if( td + lr == brown ){
            answer.push_back(i+2);
            answer.push_back((yellow / i) + 2);
            break;
        }
    }
    return answer;
}

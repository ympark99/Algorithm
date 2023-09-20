#include <string>
#include <vector>

using namespace std;

int row, col;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++) {
        row = i / n;
        col = i % n;
        
        if(row > col){
            col += row - col;
        }
        answer.push_back(col + 1);
    }
    return answer;
}

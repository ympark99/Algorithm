#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);
    
    int sum = sequence[0];
    int start = 0, end = 0;
    int min_len = 1000000001;
    
    while(start <= end && end < sequence.size()) {
        if(sum == k) {
            if(end - start < min_len) {
                min_len = end - start;
                answer[0] = start;
                answer[1] = end;
            }
            end++;
            sum += sequence[end];
        }    
        else if(sum > k) {
            sum -= sequence[start];
            start++;
        }         
        else if(sum < k) {
            end++;
            sum += sequence[end];
        }
    }
    
    return answer;
}

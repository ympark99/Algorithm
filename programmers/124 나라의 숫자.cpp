#include <string>
#include <vector>

using namespace std;

string arr[3] = {"4", "1", "2"};

string solution(int n) {
    string answer = "";
    
    while(n) {
        answer = arr[n % 3] + answer;
        if(!(n % 3)) {
            n = n / 3 - 1;
        }
        else n /= 3;
    }
    
    return answer;
}

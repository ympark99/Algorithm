#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//max 2
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int tail = people.size() - 1;
    int i = 0;
    while(i <= tail){
        if(people[i] + people[tail] <= limit){
            i++;
        }
        answer++;
        tail--;        
    }
    if(i == tail) answer++;
    return answer;
}

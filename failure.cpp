#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stop(N+1);
    vector<int> clear(N+1);
    vector<int> fail(N+1);
    vector<int> fail_sort(N+1);

    for(int i=0; i<stages.size(); i++){
        stop[stages[i]] += 1;
    }
    
    for(int i=1; i<=N; i++){
        clear[i] = clear[i-1] + stop[i];
        fail[i] = stop[i] / clear[i];
        fail_sort[i] = stop[i] / clear[i];
    }

    stable_sort(fail_sort.begin(), fail_sort.end(),desc);

    for(int i=0; i<fail_sort.size(); i++){
        for(int j=0; j<fail.size(); j++){
            if(fail[j] == fail_sort[i]){
                answer.push_back(j);
                break;
            }
        }
    }


    return answer;
}

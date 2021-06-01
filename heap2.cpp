#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int comp(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum = 0;
    int tmp = 0; // 누적 요청시간
    sort(jobs.begin(), jobs.end(), comp);

    for(int i = 0; i < jobs.size() - 1; i++){
        if(jobs[i][0] + jobs[i][1] > jobs[i+1][0]){
            swap(jobs[i],jobs[i+1]);
        }
    }

    for(int i = 0; i < jobs.size(); i++){
        sum += tmp + jobs[i][1] - jobs[i][0];
        tmp += jobs[i][1];
    }
    answer = sum / jobs.size();
    return answer;
}

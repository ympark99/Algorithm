#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

int comp(int sum){
    answer = max(answer, sum);
}

void dfs(int N, int nowtime, int sum, vector<pair<int, int>> v){

    int nextTime = nowtime + v[nowtime - 1].first;
    int nextSum = sum + v[nowtime - 1].second;

    if(nextTime - 1 > N) return;

    comp(nextSum);
    dfs(N, nextTime, nextSum, v);
    //cout << "next time : " << nextTime << "\n";
    return;
}

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for(int i = 0 ; i < N; i++){
        int timeLength, price;
        cin >> timeLength >> price;
        v.push_back(make_pair(timeLength, price));
    }

    int starttime = 1;
    int sum = 0;
    while(starttime <= N){
        dfs(N, starttime, sum, v);
        starttime++;
    //    cout << "start time : " << starttime << "\n";
    } 

    cout << answer;
}

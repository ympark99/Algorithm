#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,double> a, pair<int,double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stop;
    vector<pair<int,double>> fail;
    int chal = stages.size();

    for(int i = 0; i < N + 1; i++){
        stop.push_back(0);
    }
    for(int i = 0; i < stages.size(); i++){
        stop[stages[i]]++;
    }
    for(int i = 1; i <= N; i++){
        double failure = (double)stop[i] / (double)chal;
        if(chal == 0) fail.push_back(make_pair(i,0));
        else fail.push_back(make_pair(i, failure));
        chal -= stop[i];
    }

    sort(fail.begin(),fail.end(),comp);

    for(int i=0; i<N; i++){
        answer.push_back(fail[i].first);
    }
    return answer;
}

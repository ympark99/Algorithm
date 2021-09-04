#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    deque<pair<int, int>> dq;

    int n;
    cin >> n;

    vector<int> v;

    while(n--){
        int s, t;
        cin >> s >> t;
        dq.push_back(make_pair(s, t));
    }
    
    sort(dq.begin(), dq.end(), comp);

    int answer = 0;
    int cnt = 0;
    while(!dq.empty()){
        int i = 0;
        while(i < dq.size()){
            if(v.empty()){
                v.push_back(dq.front().second);
                answer++;
                dq.pop_front();
                continue;
            }
            if(dq[i].first >= v.back()){
                v.push_back(dq[i].second);
                dq.erase(dq.begin() + i);
            }
            else i++;           
        }
        v.clear();
    }
    cout << answer;
}

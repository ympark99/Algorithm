#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp{
    bool operator()(pair<int, int>&a, pair<int, int> &b){
        return a.second > b.second;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    int cnt = 0;

    vector<int> v; // value
    priority_queue<pair<int,int>, vector<pair<int, int>>, comp> plug; // value, many

    int many[100 + 1] = {0, };
    bool check[100 + 1] = {0, };

    int num;
    for(int i = 0; i < k; i++){
        cin >> num;
        v.push_back(num);
        many[num]++;
    } 

    for(int i = 0; i < v.size(); i++){
        if(check[v[i]]) continue;
        if(plug.size() >= n){
            cnt++;
            check[plug.top().first] = 0;
            plug.pop();
        }     
        plug.push(make_pair(v[i], many[v[i]]));
        check[v[i]] = 1;           
    }
    cout << cnt;
    
    return 0;
}

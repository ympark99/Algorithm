#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> v;
map<string, int> m;

bool comp(string a, string b){
    if(a.length() == b.length() && m[a] == m[b])
        return a < b;
    else if(m[a] == m[b])
        return a.length() > b.length();
    return m[a] > m[b];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str = "";
    for(int i = 0; i < N; i++){
        cin >> str;
        if(str.length() < M) continue;
        if(m.find(str) == m.end()){
            m[str] = 0;
            v.push_back(str);
        }
        m[str]++;        
    }
    sort(v.begin(), v.end(), comp);

    for(auto elem : v)
        cout << elem << '\n';
}

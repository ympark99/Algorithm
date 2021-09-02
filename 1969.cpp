#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    string answer = "";
    int cnt = 0;
    
    int n, m;
    cin >> n >> m;

    vector<string> v;
    string str = "";
    for(int i = 0; i < n; i++){
        cin >> str;
        v.push_back(str);
    }

    for(int i = 0; i < m; i++){
        vector<int> alpha(26);
        int idx, big = 0;
        for(int j = 0; j < n; j++){       
            alpha[v[j][i] - 'A']++;
        }
        for(int k = 0; k < 26; k++){
            if(alpha[k] > big){
                big = alpha[k];
                idx = k;
            }
        }
        answer += 'A' + idx;   
        cnt += n - big;  
    }

    cout << answer << '\n';
    cout << cnt;
    return 0;
}

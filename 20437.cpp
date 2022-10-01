#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--){
        string str; 
        int K; 
        cin >> str;
        cin >> K;
        
        vector<int> alpha(26);
        for(int i = 0; i < str.length(); i++)
            ++alpha[str[i] - 'a'];

        int minLen = INT_MAX; 
        int maxLen = -1;
        for(int i = 0; i < str.length(); ++i){
            if(alpha[str[i] - 'a'] < K)
                continue;

            int cnt = 0;
            for (int j = i; j < str.length(); ++j){
                if(str[i] == str[j])
                    ++cnt;
                
                if(cnt == K){
                    minLen = min(minLen, j - i + 1);
                    maxLen = max(maxLen, j - i + 1);
                    break;
                }
            }
        }
        
        if(minLen == INT_MAX || maxLen == -1) 
            cout << -1 << "\n";
        else 
            cout << minLen << " " << maxLen << "\n";
    }
}

#include <bits/stdc++.h>

using namespace std;

struct moves{
    int x;
    int y;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--){
        int n; 
        pair<int, int> home, festival;

        cin >> n;
        cin >> home.first >> home.second;

        vector<pair<int, int>> store(n);
        vector<bool> visitStore(n, false);
        for(int i = 0; i < n; i++){
            cin >> store[i].first >> store[i].second;
        }
        cin >> festival.first >> festival.second;

        queue<moves> q;
        q.push({home.first, home.second});
        bool isHappy = false;
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            // 편의점 1000m내에 있는지
            for(int i = 0; i < store.size(); i++)
                if((abs(store[i].first - x) + abs(store[i].second - y)) <= 1000){
                    if(!visitStore[i]){
                        visitStore[i] = true;
                        q.push({store[i].first, store[i].second});
                    }
                }

            if((abs(festival.first - x) + abs(festival.second - y)) <= 1000){
                isHappy = true;
                break;
            }
        }
        isHappy? cout << "happy" << '\n' : cout << "sad" << '\n';
    }
}

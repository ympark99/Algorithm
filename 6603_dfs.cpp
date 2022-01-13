#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int now, vector<int> v, vector<int> lotto){
    if(lotto.size() + (v.size() - now) < 6) return;

    lotto.push_back(v[now]);
    if(lotto.size() == 6){
        for(auto elem : lotto) cout << elem << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = now + 1; i < v.size(); i++){
        dfs(i, v, lotto);
    }

    return;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	while(1){
		int k; cin >> k;
		if(k == 0) break;

		vector<int> v(k);
		for(int i = 0; i < k; i++)
			cin >> v[i];

        for(int i = 0; i <= v.size() - 6; i++){
            vector<int> lotto;
            dfs(i, v, lotto);
        }

        cout << '\n';
	}

	return 0;
}

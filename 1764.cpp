#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(NULL);

	map<string, int> m;
	vector<string> v;

	int N, M;
	cin >> N >> M;

	int cnt = 0;
	string str = "";
	while(N--){
		cin >> str;
		m.insert({str, 1});
	}

	while(M--){
		cin >> str;
		if(m[str] == 1){
			v.push_back(str);
			cnt++;
		}
	}
	
	sort(v.begin(), v.end());

	cout << cnt << '\n';
	for(auto elem : v) cout << elem << '\n';

	return 0;
} 

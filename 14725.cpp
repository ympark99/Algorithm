#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<string> s;

int main() {

	int N, K, t;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> K;
		string tmp = "";
		string str = "";
		for (int j = 0; j < K; j++)
		{
			cin >> tmp;
			str += "*"+tmp;
			s.insert(str);
		}
	}
	
	for (auto elem : s) {
		int cnt = count(elem.begin(), elem.end(), '*');
		int pos = elem.find_last_of("*");
		string tmp = elem.substr(pos+1);
		for(int i = 0; i < cnt - 1; i++) 
            cout << "--";
		cout << tmp << '\n';
	}
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comp{
    bool operator()(vector<string> a, vector<string> b){
        int len = min(a.size(), b.size());
        for(int i = 0; i < len; i++){
            if(a[i] == b[i]) continue;
            return a[i] > b[i];
        }
    }
};

priority_queue<vector<string>, vector<vector<string>>, comp> pq;
int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        vector<string> tmp;
        for(int j = 0; j < K; j++){
            string str;
            cin >> str;
            tmp.push_back(str);
        }
        pq.push(tmp);
    }

    vector<string> final;
    while(!pq.empty()){
        vector<string> str = pq.top();
        pq.pop();
        
        for(int i = 0; i < str.size(); i++){
            if(final.empty()){
                final.push_back(str[i]);
                cout << str[i] << '\n';
                continue;
            }
            if(final.size() - 1 < i){
                for(int j = 0; j < i; j++)
                    cout << "--";
                cout << str[i] << '\n';
                continue;
            }
            if(final[i] == str[i]) continue;
            else{
                final[i] = str[i];
                for(int j = 0; j < i; j++)
                    cout << "--";
                cout << str[i] << '\n';
            }
        }
    }
}
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    map<string, float> m;
    string str;
    float cnt = 0;

	while (getline(cin, str)) {
		if(m.find(str) != m.end()) m[str]++;
        else m[str] = 1;
        cnt++;
	}    
    cout << fixed;
    cout.precision(4);

    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " ";
        cout << (it->second / cnt) * 100 << '\n';
    }
    return 0;
}

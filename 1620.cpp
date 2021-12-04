#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);

    map<string, int> mm;
    vector<string> v;

    string str;

    for(int i = 1; i <= n; i++){
        cin >> str;
        mm.insert({str, i});
        v.push_back(str);
    }

    for(int i = 0; i < m; i++){
        cin >> str;
        if('0' <= str[0] && str[0] <= '9') cout << v[stoi(str) - 1] << '\n';        
        else printf("%d\n", mm[str]);
    }
    return 0;
}

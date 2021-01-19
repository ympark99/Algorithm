#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string str1, string str2){
    if(str1.size() == str2.size()) return str1 < str2;
    return str1.size() < str2.size();
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<string> v;
    vector<string>::iterator iter;
    vector<string>::iterator end;    

    for(int i = 0 ; i<n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(),v.end(),compare);
    
    end = unique(v.begin(),v.end()); // 중복 제거

    for(iter = v.begin(); iter != end; iter++){
        cout << *iter << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> v;

    while(n!=0){
        v.push_back(n%10);
        n /= 10;
    }

    sort(v.begin(),v.end(),greater<>());

    for(int i =0; i<v.size();i++)
        cout << v[i];

    return 0;
}
/*
// string 이용
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string str = "";
    cin >> str;
    sort(str.begin(), str.end(), greater<>());
    cout << str;
}
*/

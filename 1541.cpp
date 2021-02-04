#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    string tmp;
    string oper;
    cin >> str;
    vector<int> v;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '-' || str[i] == '+'){
            oper += str[i];
            v.push_back(stoi(tmp));
            tmp.clear();
        }
        else if(i == str.size()-1){
            tmp += str[i];
            v.push_back(stoi(tmp));
            tmp.clear();
        }
        else tmp += str[i];
    }

    int res = v[0];
    int cnt = 0;
    while(cnt < oper.size()){
        if(oper[cnt] == '+'){
            res += v[cnt+1];
            cnt++;
        }
        else if(oper[cnt] == '-'){
            int sum = v[cnt+1];
            ++cnt;
            while (oper[cnt] == '+')
            {
                sum += v[cnt+1];
                ++cnt;
            }
            res -= sum;
        }
    }
    cout << res;
}

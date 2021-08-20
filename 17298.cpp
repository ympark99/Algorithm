#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    stack<pair<int, int>> st; // index, value
    vector<int> answer;
    answer.resize(n, -1);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);

        if(i == 0) st.push(make_pair(0, num));
        else{
            while(v[i] > st.top().second){                  
                answer[st.top().first] = v[i]; 
                st.pop();
                if(st.empty()) break;
            }
            st.push(make_pair(i, v[i]));            
        }
    }
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}

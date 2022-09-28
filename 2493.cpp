#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N+1); // height, idx
    vector<int> ans(N+1, 0);

    for(int i = 1; i <= N; i++){
        cin >> v[i].first;
        v[i].second = i;
    }

    stack<pair<int,int>> st;

    for(int i = N; i >= 1; i--){
        while(!st.empty()){
            if(v[i].first > st.top().first){
                ans[st.top().second] = v[i].second;
                st.pop();
            }
            else break;
        }
        st.push(v[i]);
    }

    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';

    return 0;
}

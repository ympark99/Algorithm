#include <iostream>
#include <queue>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,k;
    cin >> n >> k;
    queue<int> q;
    queue<int> req;

    for(int i=0; i<n; i++){
        q.push(i+1);
    }

    cout << "<";
    while (!q.empty()){
        for(int i=1; i<k; i++){
            req.push(q.front());
            q.pop();
            q.push(req.front());
            req.pop();            
        }
        cout << q.front();
        q.pop();

        if(q.empty()) cout << ">";
        else cout << ", ";
    }
	return 0;
}

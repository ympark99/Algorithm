#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    int answer = 0;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 0; i < v.size(); i++){
        answer = max(answer, v[i] * (i+1));
    }
    
    cout << answer;
}

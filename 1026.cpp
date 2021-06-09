#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v1;
    vector<int> v2;
    int answer = 0;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v1.push_back(num);
    }
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v2.push_back(num);
    }    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());

    for(int i = 0; i < N; i++){
        answer += v1[i] * v2[i];
    }

    cout << answer;
}

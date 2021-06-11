#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    vector<int> answer;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int num = 0;
        cin >> num;

        if(binary_search(v.begin(), v.end(), num)) answer.push_back(1);
        else answer.push_back(0);
    }

    for(auto elem : answer){
        cout << elem << " ";
    }
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    for(int i = 1; i <= N; i++)
        v.push_back(i);

    do{
        for(auto elem : v){
            cout << elem << ' ';
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));   
}

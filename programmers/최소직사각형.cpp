#include <bits/stdc++.h>

using namespace std;

int a, b; // 가로 세로

bool comp2(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

bool comp(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}

int solution(vector<vector<int>> sizes) {    
    sort(sizes.begin(), sizes.end(), comp);
    
    for(int i = 0; i < sizes.size(); i++) {
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        if(sizes[i][0] > a) {
            a = sizes[i][0];
        }
    }
    
    sort(sizes.begin(), sizes.end(), comp2);
    
    for(int i = 0; i < sizes.size(); i++) {
        b = max(b, sizes[i][1]);
    }
    
    return a * b;
}

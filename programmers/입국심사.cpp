#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long start = 1, end = n * (long long)times.back();
    long long mid;
    
    while(start <= end) {
        mid = (start + end) / 2;
        long long tmp = 0;
    
        for(int i = 0; i < times.size(); i++) {
            tmp += (mid / (long long) times[i]);
        }
        
        if(tmp >= n) {
            end = mid - 1;
            answer = mid;
        }
        else 
            start = mid + 1;
    }
    
    return answer;
}

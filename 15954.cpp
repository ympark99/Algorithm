#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

double mini = 9876543210;

void result(double average, int n, int k, queue<double>q2){
    double res = 0;
    while(!q2.empty()){
        res += pow((q2.front() - average),2);
        q2.pop();
    }
    res = sqrt(res/(double)k); // 표준편차

    mini = min(mini,res);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    queue<double> q2;

    int n,k;
    double sum;
    double average;
    cin >> n >> k;
    double* arr = new double[n];

    for(int i=0 ; i<n; i++){
        cin >> arr[i];
    }

    while(k <= n){
        for(int i=0; i<n; i++){
            q2.push(arr[i]);
            sum += arr[i];
            if(q2.size() == k){
                average = sum/(double)k;
                result(average, n, k, q2);
                sum -= q2.front();
                q2.pop();
            }
        }
        while(!q2.empty()){
            q2.pop();
        }
        ++k;
    }

    printf("%.11f\n",mini);

    return 0;
}

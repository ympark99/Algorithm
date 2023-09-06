#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[25][61];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0; i<book_time.size(); i++) {
        int sh = stoi(book_time[i][0].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int fh = stoi(book_time[i][1].substr(0, 2));
        int fm = stoi(book_time[i][1].substr(3, 2));
        fm += 10;
        
        if(fm > 59) {
            fh++;
            fm -= 60;
        }
        
        for(int j=sh; j<=fh; j++) {
            for(int k=0; k<60; k++) {
                if(j == sh) {
                    if(k < sm)
                        continue;
                    
                }
                if(j == fh) {
                    if(k >= fm)
                        break;
                    
                }
                arr[j][k]++;
            }
        }
    }
    
    for(int i=0; i<24; i++) {
        for(int j=0; j<60; j++) {
            if(arr[i][j] > answer)
                answer = arr[i][j];
        }
    }
    
    return answer;
}

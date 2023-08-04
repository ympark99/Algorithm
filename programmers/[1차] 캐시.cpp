#include <iostream>
#include <string>
#include <vector>
#include <deque>
 
using namespace std;
 
int solution(int cacheSize, vector<string> cities) {
 
    int answer = 0;
 
    deque<string> cache;
 
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
 
        for (int j = 0; j < city.length(); j++) {
            city[j] = tolower(city[j]);
        }
 
        bool hit = false;
        int index = 0;
        for (index = 0; index < cache.size(); index++) {
            if (cache[index] == city) {
                hit = true;
                break;
            }
        }
 
        cache.push_back(city);
 
        if (hit) {
            cache.erase(cache.begin() + index);
            answer += 1;
        }
        else {
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
    }
 
    return answer;
}

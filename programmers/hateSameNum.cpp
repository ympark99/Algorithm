#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int tmp = -1;
    for(auto elem : arr){
        if(elem != tmp)
            answer.push_back(elem);
        tmp = elem;
    }
    return answer;
}

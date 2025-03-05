#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int recent = arr[0];
    answer.push_back(recent);
    for(auto val:arr){
        if(recent!=val){
            answer.push_back(val);
        }
        recent = val;
    }
    return answer;
}
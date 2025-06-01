#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.resize(2,0);
    for(auto a: num_list){
        if(a%2==0){
            answer[0]++;
        }
        else{
            answer[1]++;
        }
    }
    return answer;
}
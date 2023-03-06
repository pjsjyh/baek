#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool first(int a, int b, int c){
    int num1 = b-a;
    int num2 = c-b;
    if(num1==num2)
        return true;
    else
        return false;
}

int solution(vector<int> common) {
    int answer = 0;
    bool istrue = first(common[0], common[1],common[2]);
    if(istrue){
        answer = common[common.size()-1]+(common[1]-common[0]);
    }
    else
    {
        if(common[0]==1){
            answer = pow(common[1],common.size());   
        }
        else{
            answer = pow(common[0],common.size()+1);
            if(common[common.size()-1]<0)
                answer = -answer;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int i=0,j=0,k=0;
    bool check = false;
    while(k!=goal.size()){
        if(goal[k]==cards1[i])
            i++;
        else if(goal[k]==cards2[j])
            j++;
        else
            check = true;
        k++;
    }
    if(check)
        answer = "No";
    else
        answer = "Yes";
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> listq;
    for (int i = 0; i < bridge_length; i++) {
        listq.push(0);
    }
    int nowweight=0, nowgo=0, count=0;
    int checknum = truck_weights[truck_weights.size()-1];
    while(true){
        int val = listq.front();
        listq.pop();
        if(val== -1) break;
        if(val!=0){
            nowweight-=val;
        }
         if(nowweight+truck_weights[nowgo]<=weight){
                listq.push(truck_weights[nowgo]);
                nowweight+=truck_weights[nowgo];
                nowgo++;
             if(nowgo>=truck_weights.size()) listq.push(-1);
        }
        else{
            listq.push(0);
        }
        count++;
    }
    answer = count;
    return answer;
}
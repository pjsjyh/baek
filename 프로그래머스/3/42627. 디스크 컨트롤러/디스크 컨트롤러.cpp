#include <string>
#include <vector>
#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> savelist;
   sort(jobs.begin(), jobs.end());
    int nowtime=0, savepoint=0;
    while(true){
        for(int j=savepoint; j<jobs.size();j++){
            if(jobs[j][0]<=nowtime){
                savelist.push({jobs[j][1], jobs[j][0]});
                savepoint+=1;
            }
            else{
                break;
            }
        }
        if(!savelist.empty()){
            int time = savelist.top().first;
            nowtime+=time;
            answer += nowtime-savelist.top().second;
            savelist.pop();
        }
        else{
            nowtime++;
        }
        if(savepoint >= jobs.size() && savelist.empty()) break;
    }
    cout<<answer<<endl;
    
    
    return answer/jobs.size();
}
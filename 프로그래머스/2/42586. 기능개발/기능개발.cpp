#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int getsize = progresses.size();
    queue<int> q;
    for(int i=0;i<getsize;i++){
        int totalval = progresses[i];
        int day=0;
        while(totalval<100){
            totalval+=speeds[i];
            day++;
        }
        q.push(day);
    }
    int recent = q.front();
    q.pop();
    int count = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(recent<a){
            answer.push_back(count);
            recent = a;
            count=1;
        }
        else{
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> qlist;
    for(int i=0;i<k;i++){
        qlist.push(0);
    }
    int totalnum=0, nowcount=0;
    for(int i=0;i<players.size();i++){
        int n = qlist.front();
        cout<<"서버의 "<<n<<"대가 사라짐"<<endl;
        nowcount-=n;
        qlist.pop();
        
        int getnum = players[i]/m;
        int calnum = getnum-nowcount;
        if(calnum>0){
            qlist.push(calnum);
            nowcount+=calnum;
            totalnum+=calnum;
        }
        else{
            qlist.push(0);
        }
        cout<<i<<"번쨰 현재 서버개수: "<<nowcount<<" 현재  total개수: "<<totalnum<<endl; 
        
        
    }

    cout<<totalnum;
    answer = totalnum;
    return answer;
}
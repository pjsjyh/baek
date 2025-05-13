#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());
    for(int i=0;i<n;i++){
        if(q.empty()) break;
        int l = q.top();
        l = l-1>=0 ? l-1 : 0;
        q.pop();
        q.push(l);
    }
    while(!q.empty()){
        int l = q.top();
        answer += pow(l,2);
        q.pop();
    }
    return answer;
}
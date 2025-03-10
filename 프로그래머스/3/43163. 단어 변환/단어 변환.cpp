#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

vector<int> visited;
int maxnum=100000000;
bool isdif(string a, string b){
    int difcount=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) difcount++;
    }
    if(difcount==1)return true;
    return false;
}
void calnum(string begin, string target, vector<string> words, int nowstep, int nowcount){
    if(begin==target){
        maxnum = min(maxnum, nowcount);
        return;
    }
    for(int i=0;i<words.size();i++){
        if(visited[i]==1)continue;
        if(isdif(begin, words[i])){
            visited[i] = 1;
            calnum(words[i], target, words, i, nowcount+1);
            visited[i] =0;
        }
        
        
    }
    
    return;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    visited.resize(words.size(),0);
    
    calnum(begin, target, words, 0 , 0);
    if(maxnum==100000000) maxnum=0;
    answer = maxnum;
    
    
  
    
    
    
    return answer;
}
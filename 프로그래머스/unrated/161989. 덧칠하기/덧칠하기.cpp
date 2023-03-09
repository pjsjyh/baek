#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int ssize=section.size();
    int* li = new int[n]{0};

    for(int i=0;i<ssize;i++){
        li[section[i]-1]=1;
    }
    for(int i=0;i<n;i++){
        if(li[i]==0)
            continue;

        for(int p=0;p<m;p++){
            if(i+p>=m) break;
            if(li[i+p]==1) li[i+p]=0;
        }
        
        i=i+m-1;
        answer++;
    }  
        
    delete[] li;
    return answer;
}
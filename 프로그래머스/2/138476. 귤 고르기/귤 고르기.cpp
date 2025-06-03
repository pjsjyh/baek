#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int mincount=10000;
void dfs(int count, vector<int> tangerine, int nownum, stack<int> list, int k){
    if(count==k){
        set<int> newset;
        stack<int> newlist = list;
        while (!newlist.empty()) {
            newset.insert(newlist.top());
            newlist.pop();
        }
         mincount = mincount>newset.size() ? newset.size() : mincount;
    }
    for(int i=nownum;i<tangerine.size();i++){
        list.push(tangerine[i]);
        dfs(count+1, tangerine, i+1, list, k);
        list.pop();
    }
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> newlist;
    for(auto a : tangerine){
        newlist[a]++;
    }
     vector<int> unique;
    for (const auto& p : newlist) {
        unique.push_back(p.first);
    }

    sort(unique.begin(), unique.end(), [&](int a, int b) {
        if (newlist[a] == newlist[b]) return a < b;
        return newlist[a] > newlist[b];             
    });
    int calnum=0, countnum=0;
     for (int num : unique) {
        calnum+=newlist[num];
         countnum+=1;
         if(calnum>=k) break;
    }
    answer = countnum;
    return answer;
}

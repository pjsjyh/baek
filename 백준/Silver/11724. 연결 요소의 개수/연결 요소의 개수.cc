#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<vector<int>> vec;
vector<int> visited;

void dfs(int start){
    if(visited[start]==1) return;
    stack<int> s;
    s.push(start);
    visited[start] = 1;
    while(!s.empty()){
        int n = s.top();
        s.pop();
        for (auto v : vec[n]) {
            if(visited[v]==0){
                s.push(v);
                visited[v]=1;
            }
        }
    }
}
int main() {
    int scount=0;
    
    int n,m;
    cin>>n>>m;
    vec.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i);
            scount++;
        }
        
    }
    cout<<scount;
    return 0;
}
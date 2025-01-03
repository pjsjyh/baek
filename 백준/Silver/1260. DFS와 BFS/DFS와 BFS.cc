#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;
   vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> bvisited;
void dfs(int node){
    visited[node] = true;
     cout << node << " "; 
    for(int n:graph[node]){
        if(!visited[n])
            dfs(n);
    }
}
void bfs(int node){
    queue<int> q;
    q.push(node);
    bvisited[node] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int n:graph[node]){
            if(!bvisited[n]){
                bvisited[n] = true;
                q.push(n);
            }
        }
    }
}

int main(){
    int n,m,v;
    cin>>n>>m>>v;
     graph.resize(n+1);
    visited.resize(n+1, false);
    bvisited.resize(n+1, false);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout<<"\n";
    bfs(v);
    return 0;
}

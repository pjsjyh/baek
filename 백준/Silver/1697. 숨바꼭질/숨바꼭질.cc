#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

int bfs(int n, int k){
     vector<bool> visited(100001,false);
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n] = true;

    while(!q.empty()){
        int c = q.front().first;
        int t = q.front().second;
        q.pop();
        if(c==k) return t;
        if(c-1>=0 && !visited[c-1]){
            visited[c-1] = true;
            q.push({c-1,t+1});
        }
        if(c+1<=100000 && !visited[c+1]){
            visited[c+1] = true;
            q.push({c+1,t+1});
        }
        if(c*2<=100000 && !visited[c*2]){
            visited[c*2] = true;
            q.push({c*2,t+1});
        }
    }
    return -1;
}
int main() {
    int n,k;
    cin>>n>>k;

    cout<<bfs(n,k);
    
    return 0;
}
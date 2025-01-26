#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> vec;
vector<bool> visited;
int thiscount=-1;
void bfs(int p1, int p2){
    queue<int> q;
    queue<pair<int,int>> qq;
    qq.push({p1,1});
    q.push(p1);

    while(!qq.empty()){
        int pe = qq.front().first;
        int count = qq.front().second;
        qq.pop();
        if(pe==p2) {thiscount = count-1; break;}
        for (auto n : vec[pe]) {
            if(visited[n]) continue;
            qq.push({n, count+1});
            visited[n] = true;
        }
    }
    cout<<thiscount;
}

int main() {
    int n;
    cin>>n;
    vec.resize(n+1);
    visited.resize(n+1,false);

    int p1,p2;
    cin>>p1>>p2;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    bfs(p1,p2);
    return 0;
}
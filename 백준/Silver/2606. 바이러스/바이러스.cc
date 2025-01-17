#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> visited;
vector<vector<int>> vec;

void bfs(int num, int leng){
    queue<int> s;
    s.push(num);
    visited[num] = true;
    while(!s.empty()){
        int n = s.front();
        s.pop();

        for(auto i : vec[n]){
            if(!visited[i]){
                visited[i] = true;
                s.push(i);
            }
        }
    }
    return;
}

int main() {
    int comp;
    cin>>comp;
    int k;
    cin>>k;
    visited.resize(comp+1, false);
    vec.resize(comp+1);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    visited[1] = true;
    bfs(1, comp);
    int count=0;
    for(auto a:visited){
        if(a) count++;
    }
    cout<<count-1;
    return 0;
}
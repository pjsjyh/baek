#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
vector<vector<int>> vec;
vector<bool> visited;
int lenv=INT_MAX;
void dfs(int start, int end, int count, int last, int cost){
    if(count==last){
        if(vec[start][0]!=0){
            if(lenv>cost+vec[start][0]) lenv = cost+vec[start][0];
            
        }
        return;
    }
    for(int i=0;i<last;i++){
        if(!visited[i]&& vec[start][i]!=0){
            visited[i] = true;
            dfs(i, end, count+1,last, cost+vec[start][i]);
            
            visited[i] = false;
        }
    }
    return;
}
int main() {
    int n;
    cin>>n;
    vec.resize(n, vector<int>(n,0));
    visited.resize(n, false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    visited[0] = true;
    dfs(0,0, 1, n,0);
    cout<<lenv;
    return 0;
}
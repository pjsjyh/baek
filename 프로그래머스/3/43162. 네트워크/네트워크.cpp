#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> vec, visited;
vector<vector<int>> list;
int count=0;
void bfs(int y, int x, int n, vector<vector<int>> computers){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=1;
    while(!q.empty()){
        int nowx = q.front().second;
        int nowy = q.front().first;
        q.pop();
        list[nowy][nowx] = count;
        for(int i=0;i<n;i++){
            if(visited[nowx][i]==0 && computers[nowx][i]==1 && nowx!=i){
                
                visited[nowx][i] = 1;
                q.push({nowx, i});
            }
        }
    }
    count++;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vec.resize(n, vector<int>(n,0));
    visited.resize(n, vector<int>(n,0));
    list.resize(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        visited[i][i]=1;
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && computers[i][j]==1){
                cout<<"돌격: "<<i<<" "<<j<<endl;
                bfs(i,j, n, computers);
            }
        }
    }
    for(int i=0;i<n;i++){
        int sumnum=0;
        for(int j=0;j<n;j++){
            sumnum+=visited[i][j];
        }
        if(sumnum==1){
            count++;
        }
    }
    cout<<count;
    answer = count;
    return answer;
}
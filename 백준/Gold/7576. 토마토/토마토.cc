#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Struct {
int y,x;
int count;
};
vector<vector<int>> vec;
vector<vector<bool>> visited;
    int m,n;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,1,0,-1};
int bigcount=0;
bool checkpass=true, changeall=true;
void bfs(){
    queue<Struct> q;
    //queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==1&&!visited[i][j]){
                q.push({i,j,0});
                visited[i][j] = true;
            }
            else{
                checkpass = false;
            }
        }
    }
    if(!checkpass){
        while(!q.empty()){
        Struct s = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = s.x+gox[i];
            int ny = s.y + goy[i];
            if(nx<0 || ny<0||nx>=m||ny>=n||visited[ny][nx]) continue;
            if(visited[ny][nx]) continue;
            if(vec[ny][nx]==0) {visited[ny][nx] = true; vec[ny][nx] = 1; q.push({ny,nx,s.count+1}); bigcount = bigcount<s.count+1 ? s.count+1 : bigcount;}
        }
    }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false&&vec[i][j]!=-1) {changeall=false; break;}
        }
    }
    if(checkpass) cout<<0;
    else if(!changeall) cout<<-1;
    else cout<<bigcount;
}

int main() {
    cin>>m>>n;
    vec.resize(n, vector<int>(m,-1));
    visited.resize(n, vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    bfs();
    return 0;
}
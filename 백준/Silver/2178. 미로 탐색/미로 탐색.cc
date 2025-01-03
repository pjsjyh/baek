#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;
 vector<vector<int>> vec;
 vector<vector<bool>> visited;
int maxcount=100;
  int n,m;
int vecx[4] = {1,0,-1,0}, vecy[4]={0,1,0,-1};
void dfs(int posx, int posy, int count){
    //cout<<posy<<" "<<posx<<" "<<count<<endl;
    //if(count) return;
    if(visited[posy][posx]==true) return;
    visited[posy][posx] = true;
    count++;            
    
    if(posx==m-1 && posy==n-1) {
        if(count<maxcount){
            maxcount = count;
        }
        visited[posy][posx] = false;
        
        count--;
        return;
    }
    
    for(int i=0;i<4;i++){
        if(posy+vecy[i]>=n || posx+vecx[i]>=m|| posy+vecy[i]<0 || posx+vecx[i]<0) continue;
//cout<<posy+vecy[i]<<" "<<posx+vecx[i]<<" "<<vec[posy+vecy[i]][posx+vecx[i]]<<"이거다"<<endl;
        if(vec[posy+vecy[i]][posx+vecx[i]]==1){
            dfs(posx+vecx[i], posy+vecy[i], count);
        }
    }
    count--;
    visited[posy][posx] = false;
    
}
int bfs(int posx, int posy, int count){
    queue<pair<pair<int, int>, int>> q;
    q.push({{posx, posy}, 1});
    visited[posy][posx] = true;

    while(!q.empty()){
        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if(nowx ==m-1 && nowy==n-1){
            return count;
        }
        for(int i=0;i<4;i++){
            int newX = nowx+vecx[i];
            int newY = nowy+vecy[i];

            if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                !visited[newY][newX] && vec[newY][newX] == 1) {
                visited[newY][newX] = true; // 방문 처리
                q.push({{newX, newY}, count + 1}); // 거리 증가
            }
        }
    }
     return -1; 
}

int main(){
  
    cin>>n>>m;
    vec.resize(n, vector<int>(m,0));
    visited.resize(n, vector<bool>(m, false));
   
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line; // 한 줄 입력받기
        for (int j = 0; j < m; j++) {
            vec[i][j] = line[j] - '0'; // 문자 -> 숫자로 변환
        }
    }
    //dfs(0,0,0);
    maxcount=bfs(0,0,0);
    cout<<maxcount;
    return 0;
}

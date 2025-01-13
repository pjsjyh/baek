#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<vector<int>> vec;
vector<vector<int>> visited;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,1,0,-1};
void dfs(int y, int x,int n){
    if(visited[y][x]==1) return;
    visited[y][x]=1;
    for(int i=0;i<4;i++){
        int nx = x+gox[i];
        int ny = y+goy[i];

        if(nx>=n||ny>=n||nx<0||ny<0) continue;
        dfs(ny, nx, n);
    }
    return;
}
int main() {
    int n;
    cin>>n;
    vec.resize(n, vector<int> (n,0));
    visited.resize(n, vector<int> (n,0));
    int mostbig=0;
    int nownum=1;
    int gibcount=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];  
            mostbig = mostbig<vec[i][j] ? vec[i][j] : mostbig;
            
        }
    }
    
    for(int i=1;i<=mostbig;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                
                //cout<<j<<" "<<k<<" "<<vec[j][k]<<endl;
                if(vec[j][k]<i) 
                {
                    visited[j][k]=1;
                }
            }
        }
        
            int count=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                //cout<<visited[j][k]<<" ";

                if(visited[j][k]==0) 
                {
                    dfs(j,k,n);
                    count++;
                }
            }
        }
            gibcount = gibcount <count ? count : gibcount;
        
        fill(visited.begin(), visited.end(), vector<int>(n, 0));

    }
    cout<<gibcount;
    return 0;
}
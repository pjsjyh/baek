#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, l,r;
vector<vector<int>> vec;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> list;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,1,0,-1};
int totalcount=0;
void calarea(int x, int y){
    
    queue<pair<int,int>> q;
    q.push({y,x});
    vector<pair<int,int>> makelist;
    makelist.push_back({y,x});
    int sumval=vec[y][x];
 visited[y][x] = true;
    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx = qx+gox[i];
            int newy = qy+goy[i];
            if(newx<0||newy<0||newx>=n||newy>=n||visited[newy][newx]) continue;
            int dnum= abs(vec[qy][qx]-vec[newy][newx]);
            if(dnum<=r && dnum>=l){
                visited[newy][newx] = true;
                q.push({newy, newx});
                makelist.push_back({newy,newx});
                sumval+=vec[newy][newx];
            }
        }
    }
    
    if(sumval!=vec[y][x]){
         int valsumval = sumval/makelist.size();
   for(int i=0;i<makelist.size();i++){
       vec[makelist[i].first][makelist[i].second] = valsumval;
       }
        
    }
    else{
        return;
    }
}

int main() {
    cin>>n>>l>>r;
    vec.resize(n, vector<int>(n,0));
    visited.resize(n, vector<bool>(n,false));
    
    for(int i=0;i<n;i++){
         for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }
    while(true){
        int docal=false;
        for(int k=0;k<n;k++){
             for (int j = 0; j < n; j++) {
                  if (visited[k][j]) continue;
                for(int i=0;i<4;i++){
                    int newx = j+gox[i];
                    int newy = k+goy[i];
                     if(newx<0||newy<0||newx>=n||newy>=n||visited[k][j]||visited[newy][newx]) continue;
                    int dnum= abs(vec[k][j]-vec[newy][newx]);
                    if(dnum<=r && dnum>=l){
                        calarea(j,k);
                        docal = true;
                        break;
                    }
                }
            }
        }
        if(!docal) break;
    visited.assign(n, vector<bool>(n, false));
        
        totalcount+=1;
    }
    cout<<totalcount;
    return 0;
}
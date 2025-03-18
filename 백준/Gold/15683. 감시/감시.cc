#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int first[4] = {1,0,0,0}, second[4] = {1,0,1,0}, third[4]={1,1,0,0}, firth[4]={1,1,1,0}, fifth[4]={1,1,1,1};
int gox[4] = {1,0,-1,0}, goy[4]={0,1,0,-1};
vector<vector<int>> vec;
vector<vector<int>> visited;
vector<pair<int,int>> cctvpos;
int timee=0;
int w,h, maxnum=1000000;
void checkcctv(){
    int num=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(visited[i][j]>0||vec[i][j]!=0){
                num+=1;
            }
        }
    }
    //cout<<"ㄱㅂ "<<w*h-num<<endl;
    maxnum = min(maxnum, w*h-num);
}
void goright(int y, int x, bool isgo){
    while(true){
        if(x>=w||vec[y][x]==6) break;
        if(isgo)
            visited[y][x]+=1;
        else
            visited[y][x]-=1;
        x++;
    }
    return;
}
void goleft(int y, int x, bool isgo){
    while(true){
        if(x<0||vec[y][x]==6) break;
        if(isgo)
            visited[y][x]+=1;
        else
            visited[y][x]-=1;
        x--;
    }
    return;
}
void gotop(int y, int x, bool isgo){
    while(true){
        if(y<0||vec[y][x]==6) break;
         if(isgo)
            visited[y][x]+=1;
        else
            visited[y][x]-=1;
        y--;
    }
    return;
}
void gobottom(int y, int x, bool isgo){
    while(true){
        if(y>=h||vec[y][x]==6) break;
         if(isgo)
            visited[y][x]+=1;
        else
            visited[y][x]-=1;
        y++;
    }
    return;
}
void dfs(int cctvnum){
    //cout<<"시작"<<cctvnum<<" "<<cctvpos.size()<<" "<<gonum<<endl;
    if(cctvnum>=cctvpos.size()) {checkcctv();return;}
    int nownum = vec[cctvpos[cctvnum].first][cctvpos[cctvnum].second];
    //cout<<"!!"<<cctvnum<<" "<<gonum<<endl;

    if(nownum==1){
        int x = cctvpos[cctvnum].second;
        int y = cctvpos[cctvnum].first;
        for(int i=0;i<4;i++){
             int nx = x, ny = y;  
            switch (i) {
                case 0:
                    goright(y,x,true);
                     dfs(cctvnum+1);
                    goright(y,x,false);
                    break;
                case 1:
                    gobottom(y,x,true);
                    dfs(cctvnum+1);
                    gobottom(y,x,false);
                    break;
                case 2:
                    goleft(y,x,true);
                    dfs(cctvnum+1);
                    goleft(y,x,false);
                    break;
                case 3:
                    gotop(y,x,true);
                    dfs(cctvnum+1);
                    gotop(y,x,false);
                    break;
            }
          
           
        }
    }
    else if(nownum==2){
        int x = cctvpos[cctvnum].second;
        int y = cctvpos[cctvnum].first;
        gotop(y,x,true);
        gobottom(y,x,true);
        dfs(cctvnum+1);
        gobottom(y,x,false);
        gotop(y,x,false);

        goright(y,x,true);
        goleft(y,x,true);
        dfs(cctvnum+1);
        goright(y,x,false);
        goleft(y,x,false);
    }
    else if(nownum==3){
         int x = cctvpos[cctvnum].second;
        int y = cctvpos[cctvnum].first;
        for(int i=0;i<4;i++){
            if(i==0){
                goright(y,x,true);
                gotop(y,x,true);
                dfs(cctvnum+1);
                goright(y,x,false);
                gotop(y,x,false);
            }
            else if(i==1){
                goright(y,x,true);
                gobottom(y,x,true);
                dfs(cctvnum+1);
                goright(y,x,false);
                gobottom(y,x,false);
            }
            else if(i==2){
                gobottom(y,x,true);
                goleft(y,x,true);
                dfs(cctvnum+1);
                gobottom(y,x,false);
                goleft(y,x,false);
            }
            else if(i==3){
                goleft(y,x,true);
                gotop(y,x,true);
                dfs(cctvnum+1);
                goleft(y,x,false);
                gotop(y,x,false);
            }
        }
    }
    else if(nownum==4){
             int x = cctvpos[cctvnum].second;
        int y = cctvpos[cctvnum].first;
        for(int i=0;i<4;i++){
            if(i==0){
                goright(y,x,true);
                gotop(y,x,true);
                 gobottom(y,x,true);
                dfs(cctvnum+1);
                goright(y,x,false);
                gotop(y,x,false);
                gobottom(y,x,false);
                
            }
            else if(i==1){
                goright(y,x,true);
                gobottom(y,x,true);
                 goleft(y,x,true);
                dfs(cctvnum+1);
                goright(y,x,false);
                gobottom(y,x,false);
                 goleft(y,x,false);
            }
            else if(i==2){
                gobottom(y,x,true);
                goleft(y,x,true);
                 gotop(y,x,true);
                dfs(cctvnum+1);
                gobottom(y,x,false);
                 gotop(y,x,false);
                goleft(y,x,false);
            }
            else if(i==3){
                goleft(y,x,true);
                 goright(y,x,true);
                gotop(y,x,true);
                dfs(cctvnum+1);
                 goright(y,x,false);
                goleft(y,x,false);
                gotop(y,x,false);
            }
        }
    }
    else if(nownum==5){
        int x = cctvpos[cctvnum].second;
        int y = cctvpos[cctvnum].first;
            gotop(y,x,true);
            goright(y,x,true);
            gobottom(y,x,true);
            goleft(y,x,true);
            dfs(cctvnum+1);
            gotop(y,x,false);
            goright(y,x,false);
            gobottom(y,x,false);
            goleft(y,x,false);
    }
}

int main() {
    cin>>h>>w;
    vec.resize(h, vector<int>(w,0));
    visited.resize(h, vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a=0;
            cin>>a;
            vec[i][j] = a;
            if(a!=0&&a!=6){
                cctvpos.push_back({i,j});
            }
            if(a==6){
                visited[i][j]=-1;
            }
        }
    }
    dfs(0);
    cout<<maxnum<<endl;
    return 0;
}
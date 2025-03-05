#include<vector>
#include <queue>
#include <iostream>
using namespace std;
int startx=0, starty=0;
vector<vector<int>> visited, nowmap;
int thissizeh,thissizew;
int gox[4] = {1,0,-1,0}, goy[4] = {0,1,0,-1};
struct ss {
    int y;
    int x;
    int count;
};
int bfs(int xpos, int ypos){
    queue<ss> q;
    q.push({ypos, xpos, 1});
    int mostbig=1000000;
    while(!q.empty()){
         ss p = q.front();
        q.pop();
        int newx = p.x;
        int newy = p.y;
        int countnew = p.count;
        for(int i=0;i<4;i++){
            int calx = newx+gox[i];
            int caly = newy+goy[i];
            if(calx<0||caly<0||calx>=thissizew||caly>=thissizeh||nowmap[caly][calx]==0|| visited[caly][calx]==1) 
                continue;

            q.push({caly, calx, countnew+1});
            if(calx ==thissizew-1 && caly==thissizeh-1){
                mostbig = mostbig>countnew+1 ? countnew+1 : mostbig;
                
            }
            visited[caly][calx]= 1;
        }
        
    }
    if (mostbig !=1000000){
        return mostbig;
    }
    return -1;

    
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    thissizeh = maps.size();
    thissizew = maps[0].size();
    nowmap = maps;
    visited.resize(thissizeh, vector<int>(thissizew,0));
    answer = bfs(0,0);
    return answer;
}
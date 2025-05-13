#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,1,0,-1};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> rect(110, vector<int>(110));
    vector<vector<int>> visited(110, vector<int>(110, 0));
    int x1, x2, y1, y2;
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] = rectangle[i][j] * 2;
		
        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                rect[y][x] = 1;
    }
    characterX*=2;
    characterY*=2;
    itemX*=2;
    itemY*=2;
    for(int i=0;i<rectangle.size();i++){
        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];
        for(int j=y1+1 ; j<y2;j++){
            for(int k=x1+1 ; k<x2;k++){
                rect[j][k]=0;
            }
        }
    }
    int length=100000;
    queue<pair<pair<int,int>, int>> q;
    q.push({{characterY, characterX},0});
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int len = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(goy[i]+y==itemY&& gox[i]+x==itemX){
                length = min((len+1)/2, length);
            }
            if(rect[goy[i]+y][gox[i]+x]==1&&visited[goy[i]+y][gox[i]+x]==0){
                visited[goy[i]+y][gox[i]+x]=1;
                q.push({{goy[i]+y, gox[i]+x}, len+1});
            }
        }
    }
    answer = length;
    return answer;
}
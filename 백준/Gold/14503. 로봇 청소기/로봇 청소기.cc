#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> vec;
int gox[4] = {0,1,0,-1};
int goy[4]={-1,0,1,0};
int totalclean=0;
void cleanroom(int ypos, int xpos, int lookat){
    if(vec[ypos][xpos]==0) {totalclean+=1;vec[ypos][xpos]=2;}

    bool checkcleaning=false;
    int firstlook = lookat;
    for(int i=0;i<4;i++){
        firstlook = (firstlook+3)%4;
        int newx = xpos+gox[firstlook];
        int newy = ypos+goy[firstlook];
        if (newx >= 0 && newy >= 0 && newx < m && newy < n && vec[newy][newx] == 0) {
             cleanroom(newy, newx, firstlook);

            checkcleaning=true;
            return; // 새로운 칸으로 이동 후 다시 청소하므로 현재 재귀 종료
        }
       
       
        
    }
    if(checkcleaning==false){
        int looklook = (lookat+2)%4;
        
        int newx = xpos+gox[looklook];
        int newy = ypos+goy[looklook];
         if(newx<0||newy<0||newx>=m||newy>=n||vec[newy][newx]==1){
             return;
        }
        else{
            cleanroom(newy, newx, lookat);
            
        }
    }
        return;
}

int main() {
    cin>>n>>m;
    int startx, starty, lookat;
    cin>>starty>>startx>>lookat;
    vec.resize(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

   cleanroom(starty, startx, lookat);
    cout<<totalclean;
    return 0;
}
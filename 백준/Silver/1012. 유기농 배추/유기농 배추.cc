#include <iostream>
using namespace std;
const int MAX_NUM = 3000;
 int place[MAX_NUM][MAX_NUM]={};

void dp(int xpos, int ypos, int xfinish, int yfinish){
    if(place[xpos][ypos]!=1){
        return;
    }
    place[xpos][ypos]=0;
    if(xpos+1<xfinish && place[xpos+1][ypos]==1){
        dp(xpos+1, ypos, xfinish, yfinish);
    }
    if(xpos-1>=0 && place[xpos-1][ypos]==1){
        dp(xpos-1, ypos, xfinish, yfinish);
    }if(ypos+1<yfinish && place[xpos][ypos+1]==1){
        dp(xpos, ypos+1, xfinish, yfinish);
    }if(ypos-1>=0 && place[xpos][ypos-1]==1){
        dp(xpos, ypos-1, xfinish, yfinish);
    }
    return;
}
int main() {
    int t;
    cin>>t;
    for(int i=0 ; i<t;i++){
        int count=0;
        int m, n, k;
        cin>>m>>n>>k;
       
        for(int j=0;j<k;j++){
            int xpos, ypos;
            cin>>xpos>>ypos;
            place[ypos][xpos] = 1;
        }
       
        for(int j=0;j<n;j++){
            for(int jj=0;jj<m;jj++){
                if(place[j][jj]==1){
                    dp(j,jj,n,m);
                    count++;
                }
            }
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}
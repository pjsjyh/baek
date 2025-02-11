#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
vector<vector<int>> vec;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,1,0,-1};



int main() {
    int n, k, l;
    cin>>n;
    cin>>k;
    vec.resize(n, vector<int>(n,0));
    for(int i=0;i<k;i++){
        int x,y;
        cin>>y>>x;
        vec[y-1][x-1]=1;
    }
    cin>>l;
    queue<pair<int, string>> q;
    for(int i=0;i<l;i++){
        int a;
        string b;
        cin>>a>>b;
        q.push({a,b});
    }
    q.push({10001, "L"});
    int now = 0;
    int totaltime=0;
    int startx=0, starty=0;
    int isfinish=false;
    queue<pair<int,int>> bam;
    set<pair<int, int>> bamSet;
    bam.push({0,0});
     bamSet.insert({0, 0});
    int recenttime=0;
    while(!q.empty()&&!isfinish){
        isfinish = false;
        int time = q.front().first;
        string bang = q.front().second;
        q.pop();
        for(int i=recenttime;i<time;i++){
            int newx = startx+gox[now];
            int newy = starty+goy[now];
            totaltime++;
            
            if(newx<0||newy<0||newx>=n||newy>=n) {isfinish = true; break;}
            if(bamSet.count({newy, newx})){
                isfinish = true; break;
            }
            startx = newx;
            starty = newy;
            if(vec[starty][startx]==1){
                 vec[starty][startx] = 0;
                bam.push({starty, startx});
                 bamSet.insert({starty, startx});
            }
            else{
                bam.push({starty, startx});
                 bamSet.insert({starty, startx});
                 pair<int, int> tail = bam.front();
                bam.pop();
                bamSet.erase(tail);
            }
        }
       if (bang == "L") {
            now = (now + 3) % 4; // 왼쪽 회전
        } else if (bang == "D") {
            now = (now + 1) % 4; // 오른쪽 회전
        }
        recenttime = time;
        
    }
    cout<<totaltime;
    return 0;
}
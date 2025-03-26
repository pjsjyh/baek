#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
struct val {
    int x;
int y;
int d;
int g;
};
int n;
vector<int> direction;
int vec[MAX][MAX];
vector<val> getval;
int cnt=0;
int gox[4] = {1,0,-1,0};
int goy[4] = {0,-1,0,1};
  int nowx,nowy;
void makeDragon(){
    int size = direction.size();
    for(int i = size - 1; i >= 0; i--){
         int temp = (direction.at(i) + 1) % 4;
        nowx+=gox[temp];
        nowy+=goy[temp];
        vec[nowy][nowx]=1;
        direction.push_back(temp);
    }
}
void Count_Square()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (vec[i][j] == 1 && vec[i][j + 1] == 1 && vec[i + 1][j + 1] && vec[i + 1][j] == 1)
                
                cnt++;
        }
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        getval.push_back({x,y,d,g});
    }
    for(int i=0;i<n;i++){
        direction.clear();
        vec[getval[i].y][getval[i].x]=1;
      
        nowx=getval[i].x+gox[getval[i].d];
        nowy=getval[i].y+goy[getval[i].d];
        vec[nowy][nowx]=1;
        direction.push_back(getval[i].d);
        for(int j=1;j<=getval[i].g;j++){
            makeDragon();
        }
    }
    Count_Square();
    cout<<cnt<<endl;
    return 0;
}
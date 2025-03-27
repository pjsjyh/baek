#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> vec;
vector<pair<int,int>> house;
vector<pair<int,int>> chiken;
vector<bool> visited;
int n, m;
int minval=10000000;
void calLen(){
    vector<pair<int,int>> nowchiken;
    for(int i=0;i<chiken.size();i++){
        if(visited[i]){
            nowchiken.push_back(chiken[i]);
        }
    }
    int totalnum=0;
    for(int i=0;i<house.size();i++){
        int minnum=10000000;
        for(int j=0;j<m;j++){
            int a = abs(nowchiken[j].first - house[i].first);
            int b = abs(nowchiken[j].second - house[i].second);
            minnum = a+b<minnum ? a+b : minnum;
        }
        totalnum+=minnum;
    }
    minval = minval>totalnum ? totalnum : minval;
}

void selectChiken(int x, int count){
    if(count==m){
        calLen();
        return;
    }
    for(int i=x;i<chiken.size();i++){
        if(!visited[i]){
             visited[i]=true;
        selectChiken(i,count+1);
        visited[i] = false;
        }
       
    }
}
int main() {
    cin>>n>>m;
    vec.resize(n, vector<int>(n,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int getn=0;
            cin>>getn;
            vec[i][j]=getn;
            if(getn==2){
                chiken.push_back({i,j});
            }
            else if(getn==1){
                house.push_back({i,j});
            }
        }
    }
    visited.resize(chiken.size(), false);

    selectChiken(0,0);
    cout<<minval;
    return 0;
}
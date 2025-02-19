#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m;
vector<vector<int>> vec;
map<string, vector<vector<pair<int,int>>>> tetrominoes = {
 {"I", {
        {{0,0}, {1,0}, {2,0}, {3,0}},  
        {{0,0}, {0,1}, {0,2}, {0,3}}
    }},
{"O", {
        {{0,0}, {1,0}, {0,1}, {1,1}},  
    }},
{"T", {
        {{2,1}, {1,0}, {0,1}, {1,1}},  
        {{1,2}, {1,0}, {0,1}, {1,1}},  
        {{0,2}, {0,0}, {0,1}, {1,1}},  
        {{1,0}, {0,0}, {2,0}, {1,1}},  
    }},
{"L", {
        {{2,1}, {1,0}, {0,0}, {2,0}},  
        {{1,0}, {1,1}, {1,2}, {0,2}},  
        {{0,0}, {2,1}, {0,1}, {1,1}},  
        {{0,1}, {0,0}, {0,2}, {1,0}},  
        {{2,0}, {2,1}, {1,1}, {0,1}},  
        {{0,0}, {1,0}, {1,1}, {1,2}},  
        {{0,0}, {0,1}, {1,0}, {2,0}},  
        {{0,0}, {0,1}, {0,2}, {1,2}},  
    }},
{"N", {
        {{0,1}, {1,0}, {1,1}, {0,2}},  
        {{0,0}, {0,1}, {1,1}, {1,2}},   
        {{0,1}, {1,0}, {1,1}, {2,0}},  
        {{0,0}, {1,0}, {1,1}, {2,1}},   
}}
};
int maxcount = 0;

void checkarea(vector<pair<int,int>> blockgroup){
     for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                int sumbig=0, checkout=0;
                 int xpos, ypos;
                 for (const auto& block : blockgroup) {
                      int newy = block.first+i;
                    int newx = block.second+j;
                      if(newy<0||newx<0||newy>=n||newx>=m){checkout=1; continue;}
                     sumbig+=vec[newy][newx];
                 }
                 
                 if(checkout==0){
                     
                     maxcount = maxcount < sumbig ? sumbig : maxcount;
                 }
             }
         }
    
}


void counttetris(){
     for (const auto& [name, shapes] : tetrominoes) {
        int rotation = 0;
        for (const auto& shape : shapes) {
            
            checkarea(shape);
        }
    }
}

int main() {
    cin >>n>>m;
    vec.resize(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    
    }
    
    counttetris();
    cout<<maxcount;
    return 0;
}
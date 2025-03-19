#include <iostream>
#include <vector>
using namespace std;
    int n, m,h;
vector<vector<pair<int,int>>> vec;
int count=100;
bool gogocheck() {
    for (int i = 0; i < n; i++) {
        int startx = i, starty = 0;

        while (starty < h) {  
            if (vec[starty][startx].first == 1) {
                startx = vec[starty][startx].second;
            }
            starty++;
        }

        if (startx != i) return false;
    }
    return true;
}

void dfs(int y, int x, int dep){
    if (dep >= 4) return; 
    if (gogocheck()) {  
        count = dep<count ? dep : count; 
    }

    for(int i=y;i<h;i++){
        for(int j=0;j<n;j++){
            if(j + 1 < n && vec[i][j].first == 0 && vec[i][j + 1].first == 0) {
                vec[i][j] = {1, j + 1};
                vec[i][j + 1] = {1, j};
    
                dfs(i, j + 1, dep + 1); 
    
                vec[i][j] = {0, j};
                vec[i][j + 1] = {0, j + 1};
            }
        }
        
    }
    return;
}

int main() {
    cin>>n>>m>>h;
    vec.resize(h, vector<pair<int,int>>(n,{0,0}));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[a-1][b-1] = {1,b};
        vec[a-1][b]={1,b-1};
    }
    if (gogocheck()) {  
        cout << 0 << endl;
        return 0;
    }
     dfs(0, 0, 0); 
    if(count==100)
        cout << -1 << endl;
    else{
        cout<<count<<endl;
    }
    return 0;
}
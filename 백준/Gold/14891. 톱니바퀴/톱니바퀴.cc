#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> allList(4, vector<int>(8)); 
int totalcount = 0;


void changethisLeft(int num, int direction, int newval) {
    if (num-1 < 0) return;

    int thisleft = newval;
    int thisright = allList[num - 1][2]; 
    if (thisleft == thisright) return; 
    int g = allList[num-1][6];
    if (direction == 1) {
         int first = allList[num-1].front();
        allList[num-1].erase(allList[num-1].begin());
        allList[num-1].push_back(first);
        changethisLeft(num - 1, -1, g);
       
    } else { 
        int last = allList[num-1].back();
        allList[num-1].pop_back();
        allList[num-1].insert(allList[num-1].begin(), last);
        changethisLeft(num - 1, 1, g);
        
    }
}


void changethisRight(int num, int direction, int newval) {
    if (num+1 >= 4) return;

    int thisright = newval;
    int thisleft = allList[num + 1][6]; 

    if (thisleft == thisright) return;
    
    int g = allList[num+1][2];
    if (direction == 1) { 
         int first = allList[num+1].front();
        allList[num+1].erase(allList[num+1].begin());
        allList[num+1].push_back(first);
        changethisRight(num + 1, -1, g); 
        
     
    } else { 
           int last = allList[num+1].back();
        allList[num+1].pop_back();
        allList[num+1].insert(allList[num+1].begin(), last);
        changethisRight(num + 1, 1, g);
        
    }
}

int main() {
   
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            allList[i][j] = s[j] - '0';
        }
    }

   
    int n;
    cin >> n;

   
    for (int i = 0; i < n; i++) {
        int num, direction;
        cin >> num >> direction;
        num--;
        changethisLeft(num, direction, allList[num][6]); // 왼쪽 톱니 회전
        changethisRight(num, direction, allList[num][2]); // 오른쪽 톱니 회전
        if (direction == 1) { // 시계 방향
            int last = allList[num].back();
            allList[num].pop_back();
            allList[num].insert(allList[num].begin(), last);
        } else { // 반시계 방향
            int first = allList[num].front();
            allList[num].erase(allList[num].begin());
            allList[num].push_back(first);
        }
    }

    // 점수 계산
    int score[4] = {1, 2, 4, 8};
    for (int i = 0; i < 4; i++) {
        if (allList[i][0] == 1) {
            totalcount += score[i];
        }
    }

    cout << totalcount << endl;
    return 0;
}

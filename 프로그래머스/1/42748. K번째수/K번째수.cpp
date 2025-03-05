#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int timecount = commands.size();
    for(int i=0;i<timecount;i++){
        vector<int> newvec;
        for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++){
            newvec.push_back(array[j]);
        }
        sort(newvec.begin(), newvec.end());
        answer.push_back(newvec[commands[i][2]-1]);
    }
    
    return answer;
}
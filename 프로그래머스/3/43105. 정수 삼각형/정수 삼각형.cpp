#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> dp;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp.resize(triangle.size());
    dp[0].push_back(triangle[0][0]);
    for(int i=1;i<triangle.size();i++){
        int k=0;
        for(int j=0;j<triangle[i].size();j++){
            int r1, r2;
            if(j-1<0) r1=0;
            else{
                r1 = dp[i-1][j-1];
            }
            if(j>i-1) r2=0;
            else{
                r2 = dp[i-1][j];
            }
            dp[i].push_back(triangle[i][j]+max(r1,r2));
            k++;
        }
    }
    answer = *max_element(dp.back().begin(), dp.back().end());
    return answer;
}
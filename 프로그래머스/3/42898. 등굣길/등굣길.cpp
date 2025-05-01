#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> dp;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    const int MOD = 1e9 + 7;
    dp.resize(n+1, vector<int>(m+1,0));
    if(!puddles[0].empty()){
         for(int i=0;i<puddles.size();i++){
            dp[puddles[i][1]][puddles[i][0]]=-1;
        }
    }
   
    dp[1][1]=1;
    if(dp[1][1]==-1) return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1 && j == 1) continue;
            if (dp[i - 1][j] > 0) dp[i][j] += dp[i - 1][j];
            if (dp[i][j - 1] > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
     
    answer = dp[n][m];
    return answer;
}
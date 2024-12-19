#include <iostream>
#include <string>
using namespace std;

const int MOD = 1'000'000'000;
int main(){
    int n;
    cin>>n;
    int sumnum=0;
    int dp[10][101]={0};
    for(int i=1;i<10;i++){
        dp[i][1] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if (j - 1 >= 0) {
                dp[j][i] = (dp[j][i] + dp[j-1][i-1]) % MOD;
            }
            if (j + 1 < 10) {
                dp[j][i] = (dp[j][i] + dp[j+1][i-1]) % MOD;
            }
        }
    }
    for(int i=0;i<10;i++){
        sumnum = (sumnum + dp[i][n]) % MOD;
    }
    cout<<sumnum%MOD;
    return 0;
}
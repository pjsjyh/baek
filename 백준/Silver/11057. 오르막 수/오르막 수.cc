#include <iostream>
using namespace std;
const int MOD =  10007;
int main() {
    int n;
    cin>>n;

    long long dp[10][1002]={0};
    for(int i=0;i<10;i++){
        dp[i][1] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int k=0;k<10;k++){
            int sum=0;
            
            for(int j=k;j<10;j++){
                sum+= dp[j][i-1];
            }
            dp[k][i]=sum%MOD;
        }
      
    }
    int count=0;
    for(int i=0;i<10;i++){
        count=(count + dp[i][n]) % MOD;
    }
    cout<<count;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long dp[100]={0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}
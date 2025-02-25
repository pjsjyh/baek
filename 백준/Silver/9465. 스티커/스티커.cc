#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int getnum;
        cin>>getnum;
        vector<vector<int>> arr, dp;
        arr.resize(2, vector<int>(getnum,0));
        dp.resize(2, vector<int>(getnum,0));
        for(int j=0;j<2;j++){
            for(int k=0;k<getnum;k++){
                cin>>arr[j][k];
                dp[j][k] = arr[j][k];
            }
        }
        dp[0][1]+=dp[1][0];
        dp[1][1]+=dp[0][0];
        for(int j=2;j<getnum;j++){
            dp[0][j] = max(dp[1][j-2]+arr[0][j], dp[1][j-1]+arr[0][j]);
            dp[1][j] = max(dp[0][j-2]+arr[1][j], dp[0][j-1]+arr[1][j]);
        }
        int val = dp[0][getnum-1]>dp[1][getnum-1]? dp[0][getnum-1] :dp[1][getnum-1];
        cout<<val<<endl;
    }
    
    return 0;
}
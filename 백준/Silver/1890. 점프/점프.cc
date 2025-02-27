#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0)); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0 || grid[i][j] == 0) continue; 

            int jump = grid[i][j];
            int nx = i + jump, ny = j + jump;

            if (nx < N) dp[nx][j] += dp[i][j];
            if (ny < N) dp[i][ny] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << endl;
    return 0;
}

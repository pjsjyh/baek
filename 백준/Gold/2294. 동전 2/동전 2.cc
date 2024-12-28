#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // 큰 값으로 초기화

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, INF); // dp 배열 초기화
    dp[0] = 0; // 0원을 만드는 데 필요한 동전 개수는 0

    for (int coin : coins) {
        for (int j = coin; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1); // 점화식
        }
    }

    if (dp[k] == INF) {
        cout << -1 << endl; // k원을 만들 수 없는 경우
    } else {
        cout << dp[k] << endl; // 최소 동전 개수 출력
    }

    return 0;
}

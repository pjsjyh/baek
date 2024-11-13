#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> t(n), p(n), sumnum(n + 1, 0);

    // 상담 일정과 보수 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        // 현재까지 계산된 최대 수익을 다음 날로 갱신
        sumnum[i + 1] = max(sumnum[i + 1], sumnum[i]);
        
        // 상담을 진행할 수 있는 경우
        if (i + t[i] <= n) {
            sumnum[i + t[i]] = max(sumnum[i + t[i]], sumnum[i] + p[i]);
        }
    }

    // n일까지의 최대 수익 출력
    cout << sumnum[n] << endl;
    return 0;
}

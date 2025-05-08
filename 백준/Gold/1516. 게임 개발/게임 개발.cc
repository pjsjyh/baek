#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int main() {
   int n;
cin >> n;

vector<int> timelist(n);
vector<int> timenum(n, 0);
vector<vector<int>> prelink(n);
vector<int> result(n, 0);

// 입력
for (int i = 0; i < n; ++i) {
    int time;
    cin >> time;
    timelist[i] = time;

    while (true) {
        int num;
        cin >> num;
        if (num == -1) break;
        prelink[num - 1].push_back(i);  // num → i
        timenum[i]++;
    }
}

// 위상 정렬
queue<int> q;
for (int i = 0; i < n; ++i) {
    if (timenum[i] == 0) {
        q.push(i);
        result[i] = timelist[i];
    }
}

while (!q.empty()) {
    int now = q.front(); q.pop();

    for (int next : prelink[now]) {
        result[next] = max(result[next], result[now] + timelist[next]);
        timenum[next]--;
        if (timenum[next] == 0) q.push(next);
    }
}

// 출력
for (int i = 0; i < n; ++i) {
    cout << result[i] << '\n';
}
return 0;
}
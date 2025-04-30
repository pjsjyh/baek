#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int minATrace = 10000000;
set<tuple<int, int, int>> visited;

void dfs(int index, int aTrace, int bTrace, const vector<vector<int>>& info, int maxATrace, int maxBTrace) {
    if (aTrace >= maxATrace || bTrace >= maxBTrace) return;
    if (aTrace >= minATrace) return;
    if (index == info.size()) {
        minATrace = aTrace;
        return;
    }

    auto key = make_tuple(index, aTrace, bTrace);
    if (visited.count(key)) return;
    visited.insert(key);

    dfs(index + 1, aTrace + info[index][0], bTrace, info, maxATrace, maxBTrace);

    dfs(index + 1, aTrace, bTrace + info[index][1], info, maxATrace, maxBTrace);
}

int solution(vector<vector<int>> info, int maxATrace, int maxBTrace) {
    minATrace = 10000000;
    visited.clear();

    int bSum = 0;
    for (const auto& item : info) bSum += item[1];
    if (bSum < maxBTrace) return 0;

    dfs(0, 0, 0, info, maxATrace, maxBTrace);

    return (minATrace == 10000000) ? -1 : minATrace;
}

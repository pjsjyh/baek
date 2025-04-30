#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 해당 숙련도(level)로 제한 시간 안에 풀 수 있는지 확인
bool check(int level, const vector<int>& diffs, const vector<int>& times, long long limit) {
    long long total = 0;

    // 첫 퍼즐은 무조건 틀리지 않음
    total += times[0];

    for (int i = 1; i < diffs.size(); ++i) {
        if (diffs[i] <= level) {
            total += times[i];
        } else {
            int failCount = diffs[i] - level;
            long long failTime = (long long)(times[i] + times[i - 1]) * failCount;
            total += failTime + times[i]; // 마지막 성공한 시간 추가
        }

        if (total > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1; // 숙련도는 1부터 시작
    int right = *max_element(diffs.begin(), diffs.end());
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid, diffs, times, limit)) {
            answer = mid;
            right = mid - 1; // 더 낮은 숙련도로도 가능한지 탐색
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

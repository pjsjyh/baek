#include <iostream>
using namespace std;

int N;
int queen[15]; // i번째 행에 놓인 퀸의 열 위치 저장
int result = 0;

bool isValid(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queen[i] == col || abs(queen[i] - col) == abs(i - row)) return false; // 같은 열 or 대각선 체크
    }
    return true;
}

void solve(int row) {
    if (row == N) { // N개의 퀸을 놓았으면 성공
        result++;
        return;
    }
    for (int col = 0; col < N; col++) { // 0~N까지 퀸 배치
        if (isValid(row, col)) { // 놓을 수 있는 위치인지 확인
            queen[row] = col; // 퀸 배치
            solve(row + 1); // 다음 행으로 이동
        }
    }
}

int main() {
    cin >> N;
    solve(0); // 0번째 행부터 시작
    cout << result << endl; // 가능한 경우 출력
    return 0;
}

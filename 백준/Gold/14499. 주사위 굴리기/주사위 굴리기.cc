#include <iostream>
#include <vector>
using namespace std;

int w, h, startx, starty, movecount;
vector<vector<int>> vec;
vector<int> moves;

// 주사위 상태 {바닥(6), 윗면(1), 앞면(2), 뒷면(5), 왼쪽(4), 오른쪽(3)}
int jusa[6] = {0, 0, 0, 0, 0, 0};  

// 이동 방향 벡터 (x: 가로, y: 세로)
int gox[4] = {1, -1, 0, 0};  // 동(→), 서(←), 북(↑), 남(↓)
int goy[4] = {0, 0, -1, 1};  // 동(0), 서(0), 북(-1), 남(+1)

void gogo(int getnum) {
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = jusa[i];

    if (getnum == 1) { // 동쪽 (→)
        jusa[0] = temp[5]; // 바닥 ← 오른쪽
        jusa[5] = temp[2]; // 오른쪽 ← 윗면
        jusa[2] = temp[4]; // 윗면 ← 왼쪽
        jusa[4] = temp[0]; // 왼쪽 ← 바닥
    } 
    else if (getnum == 2) { // 서쪽 (←)
        jusa[0] = temp[4]; // 바닥 ← 왼쪽
        jusa[4] = temp[2]; // 왼쪽 ← 윗면
        jusa[2] = temp[5]; // 윗면 ← 오른쪽
        jusa[5] = temp[0]; // 오른쪽 ← 바닥
    } 
    else if (getnum == 3) { // 북쪽 (↑)
        jusa[0] = temp[1]; // 바닥 ← 앞면
        jusa[1] = temp[2]; // 앞면 ← 윗면
        jusa[2] = temp[3]; // 윗면 ← 뒷면
        jusa[3] = temp[0]; // 뒷면 ← 바닥
    } 
    else if (getnum == 4) { // 남쪽 (↓)
        jusa[0] = temp[3]; // 바닥 ← 뒷면
        jusa[3] = temp[2]; // 뒷면 ← 윗면
        jusa[2] = temp[1]; // 윗면 ← 앞면
        jusa[1] = temp[0]; // 앞면 ← 바닥
    }
}

int main() {
    cin >> h >> w >> starty >> startx >> movecount;
    vec.resize(h, vector<int>(w));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> vec[i][j];

    moves.resize(movecount);
    for (int i = 0; i < movecount; i++)
        cin >> moves[i];

    for (int i = 0; i < movecount; i++) {
        int dir = moves[i];

        // 새로운 위치 계산 (x는 가로, y는 세로)
        int newx = startx + gox[dir - 1];
        int newy = starty + goy[dir - 1];

        // 지도 범위 체크
        if (newx < 0 || newx >= w || newy < 0 || newy >= h) continue;

        // 주사위 굴리기
        gogo(dir);

        // 지도와 주사위 바닥 값 교환
        if (vec[newy][newx] == 0) { 
            vec[newy][newx] = jusa[0]; // 바닥면 값을 지도에 복사
        } else { 
            jusa[0] = vec[newy][newx]; // 지도 값을 바닥면에 복사
            vec[newy][newx] = 0;       // 지도 값 0으로 변경
        }

        // 새로운 위치 업데이트
        startx = newx;
        starty = newy;

        // 윗면 출력
        cout << jusa[2] << endl;
    }

    return 0;
}

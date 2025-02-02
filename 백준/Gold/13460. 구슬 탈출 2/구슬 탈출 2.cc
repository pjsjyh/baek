#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

vector<vector<char>> board;
int gox[4] = {1, 0, -1, 0};
int goy[4] = {0, 1, 0, -1};
int n, m;
int red_x, red_y, blue_x, blue_y, goal_x, goal_y;

struct State {
    int rx, ry, bx, by, moves;
};

bool visited[10][10][10][10]; // 방문 체크 배열

int bfs() {
    queue<State> q;
    q.push({red_x, red_y, blue_x, blue_y, 0});
    visited[red_x][red_y][blue_x][blue_y] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.moves >= 10) return -1;  // 10번 이상 움직이면 실패

        for (int i = 0; i < 4; i++) {
            int nrx = cur.rx, nry = cur.ry, nbx = cur.bx, nby = cur.by;
            bool red_goal = false, blue_goal = false;

            // 빨간 구슬 이동
            while (board[nry + goy[i]][nrx + gox[i]] != '#' && board[nry][nrx] != 'O') {
                nrx += gox[i];
                nry += goy[i];
            }
            if (board[nry][nrx] == 'O') red_goal = true;

            // 파란 구슬 이동
            while (board[nby + goy[i]][nbx + gox[i]] != '#' && board[nby][nbx] != 'O') {
                nbx += gox[i];
                nby += goy[i];
            }
            if (board[nby][nbx] == 'O') blue_goal = true;

            // 파란 공이 구멍에 빠지면 무효
            if (blue_goal) continue;
            if (red_goal) return cur.moves + 1;  // 빨간 공만 들어가면 성공

            // 두 공이 같은 위치면, 더 늦게 도착한 공을 한 칸 뒤로
            if (nrx == nbx && nry == nby) {
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) > abs(nbx - cur.bx) + abs(nby - cur.by)) {
                    nrx -= gox[i];
                    nry -= goy[i];
                } else {
                    nbx -= gox[i];
                    nby -= goy[i];
                }
            }

            // 중복 체크
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.moves + 1});
            }
        }
    }
    return -1;  // 이동 불가능한 경우
}

int main() {
    cin >> n >> m;
    board.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') { red_x = j; red_y = i; }
            if (board[i][j] == 'B') { blue_x = j; blue_y = i; }
            if (board[i][j] == 'O') { goal_x = j; goal_y = i; }
        }
    }

    cout << bfs();
    return 0;
}

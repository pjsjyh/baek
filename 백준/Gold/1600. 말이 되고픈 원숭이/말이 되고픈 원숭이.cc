#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct State {
    int x, y;         // 현재 위치
    int moves;        // 이동 횟수
    int horseJumps;   // 남은 말 점프 횟수
};

int K, W, H;
int board[201][201];         // 격자판
bool visited[201][201][31];  // 방문 체크 (x, y, 남은 점프 횟수)

int dx[] = {1, -1, 0, 0};          // 원숭이 이동 방향
int dy[] = {0, 0, 1, -1};
int hx[] = {-2, -1, 1, 2, 2, 1, -1, -2};  // 말 점프 방향
int hy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs() {
    queue<State> q;
    q.push({0, 0, 0, K});
    visited[0][0][K] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // 도착점에 도달
        if (current.x == W - 1 && current.y == H - 1) {
            return current.moves;
        }

        // 원숭이 이동
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < W && ny >= 0 && ny < H && !visited[ny][nx][current.horseJumps] && board[ny][nx] == 0) {
                visited[ny][nx][current.horseJumps] = true;
                q.push({nx, ny, current.moves + 1, current.horseJumps});
            }
        }

        // 말 점프 이동
        if (current.horseJumps > 0) {
            for (int i = 0; i < 8; i++) {
                int nx = current.x + hx[i];
                int ny = current.y + hy[i];

                if (nx >= 0 && nx < W && ny >= 0 && ny < H && !visited[ny][nx][current.horseJumps - 1] && board[ny][nx] == 0) {
                    visited[ny][nx][current.horseJumps - 1] = true;
                    q.push({nx, ny, current.moves + 1, current.horseJumps - 1});
                }
            }
        }
    }

    return -1;  // 도달할 수 없는 경우
}

int main() {
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}

import sys



def checkRow(x, n):
    for i in range(9):
        if n == graph[x][i]:
            return False
    return True



def checkCol(y, n):
    for i in range(9):
        if n == graph[i][y]:
            return False
    return True



def checkRect(x, y, n):
    nx = x // 3 * 3
    ny = y // 3 * 3
    for i in range(3):
        for j in range(3):
            if n == graph[nx+i][ny+j]:
                return False
    return True



def solution(n):

    if n == len(blank):
        for _ in range(9):
            print(*graph[_])
        exit(0)


    for i in range(1, 10):
        x = blank[n][0] 
        y = blank[n][1] 

        if checkRow(x, i) and checkCol(y, i) and checkRect(x, y, i):
            graph[x][y] = i
            solution(n + 1)
            graph[x][y] = 0


graph = []
blank = []
for i in range(9):
    graph.append(list(map(int, sys.stdin.readline().split())))
    for j in range(9):
        if graph[i][j] == 0:
            blank.append([i, j])

solution(0)
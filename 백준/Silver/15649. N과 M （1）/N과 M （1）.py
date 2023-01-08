N,M = map(int, input().split())
result = []
visited = [False]*(N+1)

def backTracking(num):
    if num==M:
        print(' '.join(map(str,result)))
        return
    for i in range(1,N+1):
        if not visited[i]:
            visited[i]=True
            result.append(i)
            backTracking(num+1)
            visited[i] = False
            result.pop()
            
backTracking(0)            
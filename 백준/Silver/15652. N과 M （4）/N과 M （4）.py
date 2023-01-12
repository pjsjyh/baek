n,m = map(int,input().split())
li=[]
visited=[False]*(n+1)
start=1
def dfs(nn):
    global start
    if nn == m:
        print(' '.join(map(str,li)))
        return
    for i in range(start,n+1):
        visited[i] = True
        
        start=i
        li.append(i)
        dfs(nn+1)
        visited[i]=False
        li.pop()
            
  
                


dfs(0)

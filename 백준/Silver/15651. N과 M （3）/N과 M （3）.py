n,m = map(int,input().split())
li=[]
visited=[False]*(n+1)
def dfs(nn):
    if nn == m:
        print(' '.join(map(str,li)))
        return
    for i in range(1,n+1):
        visited[i] = True
        li.append(i)
        dfs(nn+1)
        visited[i]=False
        li.pop()
            
  
                


dfs(0)

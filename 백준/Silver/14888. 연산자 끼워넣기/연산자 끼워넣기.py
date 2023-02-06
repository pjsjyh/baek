n = int(input())
li =list(map(int,input().split()))
add,sub,mul,div = (map(int,input().split()))



max1=-1000000000
min1=1000000000

def dfs(i,arr):
    global add,sub,mul,div, max1,min1
    
    if i==n:
        max1 = max(max1, arr)
        min1 = min(min1, arr)
    else:
        if add>0:
            add-=1
            dfs(i+1, arr+li[i])
            add+=1
        if sub>0:
            sub-=1
            dfs(i+1,arr-li[i])
            sub+=1
        if mul>0:
            mul-=1
            dfs(i+1,arr*li[i])
            mul+=1
        if div>0:
            div-=1
            if(arr<0):
                dfs(i+1,-(-arr//li[i]))
            else:
                dfs(i+1,arr//li[i])
            div+=1
            
dfs(1,li[0])

print(int(max1))
print(int(min1))

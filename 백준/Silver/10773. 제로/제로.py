
k = int(input())
isb=[]

for i in range(k):
    n = int(input())
    if n==0:
        isb.pop()
    else:
        isb.append(n)
result = sum(isb)

print(result)

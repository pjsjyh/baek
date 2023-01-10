n,cut = map(int,input().split())

aa = list(map(int,input().split()))


k=n-1
for i in range(n):
    for j in range(k):
        if(aa[j]>aa[j+1]):
           p = aa[j]
           aa[j] = aa[j+1]
           aa[j+1] = p
    k-=1
print(aa[n-cut])
          
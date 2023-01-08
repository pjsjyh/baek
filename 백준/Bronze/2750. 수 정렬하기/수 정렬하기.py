n = int(input())
a=[]
for i in range(n):
    aa = int(input())
    a.append(aa)
k=n-1
for i in range(n):
    for j in range(k):
        if(a[j]>a[j+1]):
           p = a[j]
           a[j] = a[j+1]
           a[j+1] = p
    k-=1
for i in range(n):
    print(a[i])

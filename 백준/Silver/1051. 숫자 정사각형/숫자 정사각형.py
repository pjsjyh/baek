n,m = map(int,input().split())
a=[]
aa=[]
for i in range(n):
    aa.append(input())
for i in range(len(aa)):
    a.append([])
    for j in str(aa[i]):
        a[i].append(int(j))
s=0
if n>m:
    s=m
else:
    s=n
total=0
i=0
j=0
finish=False
while(s>1):
    while(True):
        
        if((i+s-1>=n)==True):
            break
        while(True):
            if((j+s-1>=m)==True):
                break
            
            if(a[i][j] == a[i][j+s-1] and  a[i][j+s-1]==a[i+s-1][j] and a[i+s-1][j] == a[i+s-1][j+s-1]):

                finish=True
                break
            j+=1
        if(finish==True):
            break
        i+=1
        j=0

    if(finish==True):
        break    
    s-=1
    j=0
    i=0
    
if(finish==True):
    print(s*s)
else:
    print(1)

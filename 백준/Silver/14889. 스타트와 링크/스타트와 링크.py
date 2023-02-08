from itertools import combinations
n = int(input())
li=[]
nli=[]
for i in range(n):
    nli.append(i)
    li.append(list(map(int,input().split())))

a = list(combinations(nli,int(n/2)))

lena = len(a)
mins=1000000000
for i in range(lena):
    first=[]
    second=[]
    f=0
    s=0
    for j in range(int(n)):
        if(j not in a[i]):
            second.append(j)
        else:
            first.append(j)
    for j in range(int(n/2)):
        for k in range(j,int(n/2)):
            f+=li[first[j]][first[k]]
            f+=li[first[k]][first[j]]
            s+=li[second[j]][second[k]]
            s+=li[second[k]][second[j]]
    q = abs(f-s)
    if (q<mins):
        mins=q
print(mins)

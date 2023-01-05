num = int(input())
go=[]
length=[]
for i in range(6):
    g,l = map(int,input().split())
    go.append(g)
    length.append(l)
check=0
i=0
a=0
wbig=0
hbig=0
minusarea=0
for i in range(6):
    if(i==5):
        a=0
    else:
        a=i+1
    if(go[i]==1):
        if(wbig<length[i]):
            wbig = length[i]
        if(go[a]!=4):
            check = i
            minusarea = length[i]*length[a]
    elif(go[i]==2):
        if(wbig<length[i]):
            wbig = length[i]
        if(go[a]!=3):
            check=i
            minusarea = length[i]*length[a]
    elif(go[i]==3):
        if(hbig<length[i]):
            hbig = length[i]
        if(go[a]!=1):
            check=i
            minusarea = length[i]*length[a]
    elif(go[i]==4):
        if(hbig<length[i]):
            hbig = length[i]
        if(go[a]!=2):
            check=i
            minusarea = length[i]*length[a]

area = wbig*hbig
print((area-minusarea)*num)

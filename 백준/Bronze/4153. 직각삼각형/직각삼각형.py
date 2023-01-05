a=[]
b=[]
c=[]
while(True):
    aa,bb,cc = map(int,input().split())
    if(aa==0 and bb==0 and cc==0):
        break
    a.append(aa)
    b.append(bb)
    c.append(cc)
for i in range(len(a)):
    if(a[i]>b[i] and a[i]>c[i]):
        if(b[i]**2+c[i]**2==a[i]**2):
            print("right")
        else:
            print("wrong")
    elif(b[i]>a[i] and b[i]>c[i]):
        if(a[i]**2+c[i]**2==b[i]**2):
            print("right")
        else:
            print("wrong")
    elif(c[i]>a[i] and c[i]>b[i]):
        if(a[i]**2+b[i]**2 == c[i]**2):
            print("right")
        else:
            print("wrong")
    else:
        print("wrong")

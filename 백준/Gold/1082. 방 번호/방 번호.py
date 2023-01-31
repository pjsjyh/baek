n = int(input())

li = list(map(int,input().split()))
m = int(input())

money=[]
cash=0
minn=100
mini=0
minn1=100
mini1=0
for i in range(0,len(li)):
    if li[i]<minn and li[i]<=m:
        minn=li[i]
        mini=i
    if i>0:
        if li[i]<minn1 and li[i]<=m:
            minn1=li[i]
            mini1=i

if minn==0 and mini1==0:
    print(0)
else:
    money.append(mini1)
    cash+=minn1
    while(True):
        if cash+minn<=m:
            cash+=minn
            money.append(mini)
        else:
            break
    for i in range(len(money)):
        for j in range(len(li)):
            if(i==0 and li[j]==0):
                continue
            if(money[i]<=j and li[money[i]]<=li[j]):
                if(cash-li[money[i]]+li[j]<=m):
                    cash=cash-li[money[i]]+li[j]
                    money[i] = j
    for i in range(len(money)):
        money[i] = str(money[i])
    print(''.join(money))    
                
    
    

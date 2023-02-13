n = int(input())
a=[]
for i in range(n):
    a.append(int(input()))

i=0
j=1
while(True):
    s1 = a[j]-a[i]
    s2 = a[j]//a[i]
    
    if(a[j]+s1==a[j+1] and a[j]*s2==a[j+1]):
        j+=1
        i+=1
        continue
    elif(a[j]+s1==a[j+1] ):
        print(a[n-1]+s1)
        break
    else:
        print(a[n-1]*s2)
        break
    


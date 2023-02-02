n = int(input())

time=1
i=1
sum=0
while(True):
    if (n<time):
        break
    time+=i
    i+=1
i = i-1
for j in range(i):
    sum+=j
if(i%2==0):
    print(str(n-sum)+'/'+str(i-(n-sum-1)))
else:
    print(str(i-(n-sum-1))+'/'+str(n-sum))

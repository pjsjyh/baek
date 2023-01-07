baek = [0 for i in range(10000)]

for i in range(1,10000):
    c=0
    d=0
    a = i%10
    if(i<10):
        b=0
    elif(i<100):
        b=i//10
    elif(i<1000):
        b = i//100
        bb = i%100
        c=bb//10
    else:
        d=i//1000
        dd=i%1000
        b = dd//100
        bb = dd%100
        c=bb//10
    num = i+a+b+c+d

    baek[i] = num
    


for i in range(len(baek)):
    if(i not in baek):
        print(i)



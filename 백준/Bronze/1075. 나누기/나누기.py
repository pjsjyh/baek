n = int(input())
f = int(input())
n3 = str(n)[len(str(n))-3]
a = n%f
if a!=0:
    n=n+(f-a)

while(True):
    k = n-f
    if n-f==0:
        break
    if str(k)[len(str(k))-3]==n3:
        n = k
    else:
        break
print((str(n)[len(str(n))-2])+(str(n)[len(str(n))-1]))
    

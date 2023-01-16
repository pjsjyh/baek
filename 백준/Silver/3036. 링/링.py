
def gcd(a, b):
    while(b != 0):
        n = a%b
        a = b
        b = n
    return a
n = int(input())
a = list(map(int,input().split()))
for j in range(1,n):
    g = gcd(a[0],a[j])
    print('{0}/{1}'.format(a[0]//g,a[j]//g))


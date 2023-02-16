n = int(input())
lin = list(map(int,input().split()))
m = int(input())
lim = list(map(int,input().split()))

lin.sort()

def binary(start, end, array, target):
    if start>end:
        return 0
    mid = (start+end)//2
    if(array[mid]==target):
        return 1
    elif array[mid]>target:
        return binary(start, mid-1, array, target)
    else:
        return binary(mid+1, end, array, target)

for i in range (m):
    result =binary(0,len(lin)-1,lin,lim[i])
    print(result)


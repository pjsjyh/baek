x,y,w,h = map(int,input().split())

a=[w-x,x,h-y,y]
min=10000
for i in range(4):
    if a[i]<min:
        min = a[i]
print(min)

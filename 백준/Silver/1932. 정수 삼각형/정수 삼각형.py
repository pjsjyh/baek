n = int(input())
s = []

for i in range(n) :                            
    s.append(list(map(int,input().split())))


for i in range(1,n) :                           
    for j in range(0,i+1) :                     
        if j == 0 :
            s[i][0] += s[i-1][0]              
        elif j == i :
            s[i][j] += s[i-1][j-1]            
        else :
            s[i][j] += max(s[i-1][j-1],s[i-1][j])    

print(max(s[n-1]))  
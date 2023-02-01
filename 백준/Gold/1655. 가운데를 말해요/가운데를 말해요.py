import sys
import heapq
n = int(sys.stdin.readline())
leftheap=[]
rightheap=[]


for i in range(n):
    num = (int(sys.stdin.readline()))
    if len(leftheap)==len(rightheap):
        heapq.heappush(leftheap, -num)
    else:
        heapq.heappush(rightheap, num)

    if rightheap and rightheap[0] < -leftheap[0]:
        leftValue = heapq.heappop(leftheap)
        rightValue = heapq.heappop(rightheap)

        heapq.heappush(leftheap, -rightValue)
        heapq.heappush(rightheap, -leftValue)
    print(-leftheap[0])
import sys
import math
input = lambda: sys.stdin.readline().rstrip()
inf=float('inf')
for case in range(int(input())):
    n = int(input())
    a = [inf] + list(map(int, input().split()))
    s=set(a)
    if len(s)==2:
        print(0)
        continue
    if 1 in s:
        print(-1)
        continue
    res=[]
    idx=-1
    while True:
        k=min(a)
        idx=a.index(k)
        if k in [1]:
            print(-1)
            break
        for i in range(1,n+1):
            while a[i]>k:
                a[i]/=k
                a[i]=math.ceil(a[i])
                res.append((i,idx))
        if min(a)==k:
            if len(set(a)) == 2:
                print(len(res))
                for i in res:
                    print(*i)
            else:
                print(-1)
            break

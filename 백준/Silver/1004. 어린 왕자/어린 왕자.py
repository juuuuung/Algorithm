import sys
T = int(sys.stdin.readline())
Cnt = [0 for _ in range(T)]
for __ in range(T):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    n = int(input())
    for _ in range(n):
        x, y, r = list(map(int, sys.stdin.readline().split()))[:3]

        #두점 사이 거리 d
        sd = (abs(x-x1)**2+abs(y-y1)**2)**0.5
        ed = (abs(x-x2)**2+abs(y-y2)**2)**0.5

        if sd < r and ed < r:
            pass
        elif sd < r or ed < r:
            Cnt[__] += 1
        else:
            continue

for i in Cnt:
    print(i)
    
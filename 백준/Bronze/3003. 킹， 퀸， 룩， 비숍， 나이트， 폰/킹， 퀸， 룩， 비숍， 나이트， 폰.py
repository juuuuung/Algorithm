officialList = [1, 1, 2, 2, 2, 8]
haveList = list(map(int, input().split()))
needList = [0 for _ in range(6)]

for _ in range(6):
    needList[_] = officialList[_] - haveList[_]

print(*needList)
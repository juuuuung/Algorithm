import sys
a, b= sys.stdin.readline().split()
strList = ["", ""]

for _ in range(2, -1, -1):
    strList[0] += a[_]
    strList[1] += b[_]

strList = list(map(int, strList))

if strList[0] > strList[1]:
    print(strList[0])
else:
    print(strList[1])

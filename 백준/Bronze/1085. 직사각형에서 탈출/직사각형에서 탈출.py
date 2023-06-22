import sys
input = sys.stdin.readline
x,y,w,h = map(int, input().split())

result = [0,0]

if abs(w-x) < x:
    result[0] = abs(w-x)
else:
    result[0] = x

if abs(y-h) < y:
    result[1] = abs(y-h)
else:
    result[1] = y

print(result[result[0] > result[1]])
import sys
S = sys.stdin.readline().replace("\n", "")
if S == S[-1::-1]:
    print(1)
else:
    print(0)
n = int(input())
arr = [0 for _ in range(101)]
cnt = 0
for i in list(map(int, input().split())):
    if arr[i] == 1:
        cnt += 1
    else:
        arr[i] = 1

print(cnt)
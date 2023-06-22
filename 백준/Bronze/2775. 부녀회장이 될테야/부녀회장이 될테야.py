import sys
T = int(input())
for _ in range(T):
    H = int(sys.stdin.readline()) - 1
    room_num = int(sys.stdin.readline())
    arr = [int(n*(n+1)/2) for n in range(1,room_num+1)]
    for i in range(H):
        for n in range(1, len(arr)):
            arr[n] = arr[n-1] + arr[n]
    print(arr[room_num-1])
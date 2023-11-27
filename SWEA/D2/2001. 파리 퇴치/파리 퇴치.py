T = int(input())
for i in range(T):
  N,M = list(map(int, input().split()))
  board = [list(map(int, input().split())) for _ in range(N)]
  MAX = 0
  for j in range((N-M)+1):
    for k in range((N-M)+1):
      total = 0
      
      for a in range(M):
        for b in range(M):
          total+=board[j+a][k+b]
      MAX = max(total, MAX)
  print(f"#{i+1} {MAX}")
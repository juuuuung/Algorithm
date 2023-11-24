from sys import stdin as s

def backtrack(nxt_idx, total_val):
  if nxt_idx >= len(num_list):
    global this_MAX 
    global this_MIN
    this_MAX = max(this_MAX, total_val)
    this_MIN = min(this_MIN, total_val)
    return

  for i in range(4):
    if(oper_list[i]):
      oper_list[i]-=1
      if i == 0:
        backtrack(nxt_idx +1, total_val + num_list[nxt_idx])
        oper_list[i]+=1
      elif i == 1:
        backtrack(nxt_idx+1, total_val - num_list[nxt_idx])
        oper_list[i]+=1
      elif i == 2:
        backtrack(nxt_idx+1, total_val * num_list[nxt_idx])
        oper_list[i]+=1
      else:
        if total_val < 0:
          backtrack(nxt_idx+1, (-1*((-1*total_val) // num_list[nxt_idx])))
          oper_list[i]+=1
        else:
          backtrack(nxt_idx+1, total_val // num_list[nxt_idx])
          oper_list[i]+=1

N = int(s.readline().rstrip())
num_list = list(map(int, s.readline().rstrip().split()))
oper_list = list(map(int, s.readline().rstrip().split()))
global this_MAX 
global this_MIN
this_MAX = -1_000_000_000
this_MIN = 1_000_000_000

backtrack(1, num_list[0])
print(this_MAX,this_MIN)
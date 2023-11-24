from sys import stdin as s

input = int(s.readline().strip())

num = 0
total = 0
while (total:=(total+(num:=num+1))) <= input:
  pass

print(num-1) if input != 1 else print(1)
import sys
a = sys.stdin.readline().replace("\n", "").upper()
cnt = {}

for i in list(set(a)):
    cnt[i] = a.count(i)

keys = list(cnt.keys())
value = list(cnt.values())

if value.count(max(value)) == 1:
    print(keys[value.index(max(value))])
else:
    print("?")
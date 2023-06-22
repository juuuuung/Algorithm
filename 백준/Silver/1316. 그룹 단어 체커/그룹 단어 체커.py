import re, sys
T = int(sys.stdin.readline())
cnt = 0

for _ in range(T):
    word = sys.stdin.readline()
    alphabet = list(set(word))
    cnt += 1
    for i in alphabet:
        match = re.search(f"{i}[^{i}]+{i}", word)
        if match:
            cnt -=1
            break
print(cnt)
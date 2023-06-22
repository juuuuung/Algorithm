alphabet = ["a", "e", "i", "o", "u"]
resultList = []
while (s:=input())[0] != "#":
    cnt = 0
    s = s.lower()
    for _ in alphabet:
        cnt += s.count(_)
    resultList.append(cnt)

print(*resultList, sep="\n")
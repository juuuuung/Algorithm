N = int(input())
gradeList = list(map(int, input().split()))
maxgrade = max(gradeList)

gradeList = list(map(lambda x : x/maxgrade *100, gradeList))
print(sum(gradeList)/N)
hour, minute = map(int, input().split(" "))
after_minute = minute + 15

if after_minute >= 60:
    print(hour, after_minute%60)
else:
    if hour-1 == -1:
        print(23, after_minute)
    else :
        print(hour-1, after_minute)

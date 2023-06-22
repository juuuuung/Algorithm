def fibo(a,b,n):
    if n == 0:
        return [1,0]
    elif n == 1:
        return [a,b]
    return fibo(b, b+a, n-1)


def main(): 
    T = int(input())
    while (T:=T-1) >= 0:
        print(*fibo(0,1,int(input())))
    
if __name__ == "__main__":
    main()

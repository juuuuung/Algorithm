def solution(n):
    dp = [0 for _ in range(100_002)]
    dp[1] = 1
    for i in range(2, 100_001):
        if(dp[i]==0):
            dp[i] = dp[i-1] + dp[i-2]
    return dp[n] % 1234567
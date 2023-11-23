#include <bits/stdc++.h>

using namespace std;
int T, stairs[302], dp[302][2];
int main(void){
  cin >> T;
  for(int i = 1; i <= T; ++i) cin >> stairs[i];

  dp[1][0] = stairs[1], dp[2][0] = stairs[2];
  dp[1][1] = stairs[1], dp[2][1] = stairs[1]+stairs[2];

  for(int i = 3; i <= T; ++i){
    dp[i][0] = max(dp[i-2][0], dp[i-2][1])+stairs[i];
    dp[i][1] = dp[i-1][0] + stairs[i];
  }
  cout << max(dp[T][0], dp[T][1]) << '\n';
  return 0;
}
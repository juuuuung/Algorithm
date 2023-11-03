#include <bits/stdc++.h>

using namespace std;

int main(void){
  int dp[1'000'002] = {0,};
  dp[2] = 1, dp[3] = 1;
  for(int i = 4; i <= 1'000'001; ++i){
    int minCnt = 2'000'000'001;
    if(i%2 == 0 && (dp[i/2] + 1) < minCnt) minCnt = dp[i/2]+1;
    if(i%3 == 0 && (dp[i/3] + 1) < minCnt) minCnt = dp[i/3]+1;
    if((dp[i-1] + 1) < minCnt) minCnt = dp[i-1]+1;
    dp[i] = minCnt;
  }
  int num;
  cin >> num;
  cout << dp[num];
  return 0;
}
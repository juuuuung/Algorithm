#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, Max;
int dp[100'001];
int main(){
  init();
  cin >> n;
  Max = sqrt(n);
  fill(dp, dp+n+1, 100'002);
  dp[1] = 1;
  dp[0] = 0;
  for(int i = 1; i <= Max+1; ++i)
    for(int j = (i*i); j <=n; ++j)
      dp[j]= min(dp[j], dp[j-(i*i)]+1);
  cout << dp[n];  
  return 0;
}
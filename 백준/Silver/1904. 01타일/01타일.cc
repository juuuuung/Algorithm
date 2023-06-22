#include <bits/stdc++.h>
#define mod 15746
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n;
int dp[1'000'001];
int main(){
  init();
  cin >> n;
  dp[1] = 1;dp[2] = 2;dp[3] = 3;
  for(int i = 4; i <= n; ++i) dp[i] = (dp[i-1] + dp[i-2])%mod;
  cout << dp[n]%mod;
  return 0;
}
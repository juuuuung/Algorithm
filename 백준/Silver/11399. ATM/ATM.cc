#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
int dp[1002];

int main(){
  init();
  cin >> n;
  for(int i= 1; i <= n; ++i) cin >> dp[i];
  sort(dp+1, dp+n+1);
  int ans = dp[1];
  for(int i = 2; i <= n; ++i){
    dp[i] += dp[i-1];
    ans += dp[i];
  }
  cout << ans;
  return 0;
}
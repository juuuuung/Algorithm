#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int T, n, money;
int coin[21];
int dp[10'005];

int main(){
  init();
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> coin[i];
    cin >> money;
    fill(dp, dp+money+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
      for(int j = coin[i]; j <= money; ++j){
        dp[j] += dp[j-coin[i]];
      }
    }
    cout << dp[money]<<'\n';
  }
  return 0;
}
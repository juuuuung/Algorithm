#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int t, n;
int dp[2][100'002];
int main(){
  init();
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=0; i < 2; ++i)
      for(int j = 1; j<=n; ++j)
        cin >> dp[i][j];
    dp[0][2] += dp[1][1];
    dp[1][2] += dp[0][1];
    for(int j = 3; j <= n; ++j){
      dp[0][j] += max(dp[1][j-2], dp[1][j-1]);
      dp[1][j] += max(dp[0][j-2], dp[0][j-1]);
    }  
    cout << max(dp[0][n], dp[1][n]) << '\n';
  }
  return 0;
}
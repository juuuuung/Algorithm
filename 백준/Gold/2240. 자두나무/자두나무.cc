#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int t, w;
int arr[1001];
int dp[1001][31][3];

int main(){
  init();
  cin >> t >> w;
  for(int i = 1; i <= t; ++i) cin >> arr[i];

  for(int i = 0; i <= w; ++i){
    for(int j = 1; j <= t; ++j){
      if(i == 0)dp[j][0][1] = dp[j-1][0][1] + (arr[j]==1);
      else{
        dp[j][i][1] = max(dp[j-1][i][1], dp[j-1][i-1][2]) + (arr[j] == 1);
        dp[j][i][2] = max(dp[j-1][i][2], dp[j-1][i-1][1]) + (arr[j] == 2);
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= 2; ++i)
    for(int j = 0; j <= w; ++j)
      ans = max(ans, dp[t][j][i]);
  cout << ans;
  return 0;
}
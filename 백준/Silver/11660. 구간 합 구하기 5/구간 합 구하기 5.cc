#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, t;
int board[1025][1025];
int dp[1025][1025];

int main(){
  init();
  cin >> n >> t;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      cin >> board[i][j];
      if(i == 1) dp[i][j] =dp[i][j-1] + board[i][j];
      if(j == 1) dp[i][j] =dp[i-1][j] + board[i][j];
    }
  }

  for(int i = 2; i <= n; ++i)
    for(int j = 2; j <= n; ++j)
      dp[i][j] = dp[i-1][j] + dp[i][j-1] -  dp[i-1][j-1] + board[i][j];

  while(t--){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dp[x2][y2] -(dp[x1-1][y2] + dp[x2][y1-1]) + dp[x1-1][y1-1] << '\n'; 
  }
  return 0;
}
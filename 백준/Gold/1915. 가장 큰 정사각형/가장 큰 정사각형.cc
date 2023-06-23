#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
int arr[1002][1002], dp[1002][1002];
int main(){
  init();
  cin >> n >> m;

  for(int i = 1; i <= n; ++i){
    string str;
    cin >> str;
    for(int j = 1; j <= m; ++j){
      arr[i][j] =str[j-1]-'0';
    }
  }
  
  int ans = 0;
  for(int x = 1; x <= n; ++x)
    for(int y = 1; y <= m; ++y)
      if(arr[x][y]){
        dp[x][y] = min({dp[x-1][y], dp[x][y-1], dp[x-1][y-1]}) + 1;
        ans = max(ans, dp[x][y]);
      }
  cout << ans * ans;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
bool dp[1001];

int main(){
  init();
  cin >> n;
  dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1;

  for(int i = 5; i <= n; ++i){
    if(!dp[i-1] || !dp[i-3] || !dp[i-4]){
      dp[i] = 1;
    }else if(dp[i-1] && dp[i-3] && dp[i-4]){
      dp[i] = 0;
    }
  }
  cout << (dp[n] == 1? "SK" : "CY");


  return 0;
}
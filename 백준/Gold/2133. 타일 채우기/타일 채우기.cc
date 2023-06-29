#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
long long dp[32];

int main(){
  init();
  cin >> n;
  if(n % 2 != 0){
    cout << 0;
    return 0;
  }
  dp[2] = 3;
  for(int i = 4; i <= n; ++i){
    dp[i] = dp[2] * dp[i-2];
    for(int j = 0; j <= i-4; j+=2){
      dp[i] += dp[j] * 2;
    }
    dp[i] += 2;
  }
  cout << dp[n];
  return 0;
}
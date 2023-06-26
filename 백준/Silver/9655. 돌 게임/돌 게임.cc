#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
//1, 3 sk 승 = 1
//2, 4 cy 승 = 0
bool dp[1002];

int main(){
  init();
  cin >> n;
  dp[1] = dp[3] = 1;
  for(int i = 5; i <= n; ++i){
    dp[i] = ((dp[i-3] == 1 && dp[i-1] == 1) ? 0 : 1);
  }
  cout << (dp[n] ? "SK" : "CY") << '\n';

  return 0;
}
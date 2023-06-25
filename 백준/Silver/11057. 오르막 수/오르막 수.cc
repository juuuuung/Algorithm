#include <bits/stdc++.h>
#define mod 10'007
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
unsigned long long dp[11];

int main(){
  init();
  cin >> n;
  for(int i = 0; i < 10; ++i) dp[i] = 1;

  for(int i = 1; i < n; ++i)
    for(int j = 0; j <= 9; ++j)
      dp[j] = accumulate(dp + j, end(dp), 0) % mod;

  cout << accumulate(dp, end(dp), 0) %mod;

  return 0;
}
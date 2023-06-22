#include <bits/stdc++.h>
#define mod 1'000'000'000

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, absN;
int dp[1'000'002];

int main(){
  init();
  cin >> n;
  absN = abs(n);
  if(n > 0){
    dp[1] = 1;
    for(int i = 2; i <= n; ++i) dp[i] = (dp[i-1] + dp[i-2]) % mod;
  }else if(n < 0){
    dp[1] = 1; 
    for(int i = 2; i <= absN; ++i) dp[i] = (dp[i-2] - dp[i-1])%mod;
  }
  cout << ((dp[absN] < 0) ? -1 : (dp[absN] == 0) ? 0 : 1) << '\n' << abs(dp[absN]);
  return 0;
}
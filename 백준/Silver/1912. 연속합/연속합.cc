#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int Max, n, arr[100'001], dp[100'001];
int main(){
  init();
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> arr[i];
  dp[1]=Max= arr[1];
  for(int i = 2; i <= n; ++i){
    dp[i] = max(dp[i-1]+arr[i], arr[i]);
    Max = max(Max, dp[i]);
    if(dp[i] < 0) dp[i] = 0;
  }
  cout << Max;
  return 0;
}
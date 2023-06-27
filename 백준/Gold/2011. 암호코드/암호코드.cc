#include <bits/stdc++.h>
#define mod 1000000

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int arr[5002], dp[5002];

int main(){
  init();
  string s; cin >> s;
  for(int i = 1; i <= s.size(); ++i){
    arr[i] = s[i-1]-'0';
  }
  dp[0] = 1;
  for(int i = 1; i <= s.size(); ++i){
    if(arr[i] > 0)dp[i] = (dp[i-1] + dp[i])%mod;
    int x = arr[i-1] * 10 + arr[i];
    if(10 <= x && x <= 26){
      dp[i] = (dp[i-2] + dp[i])%mod;
    }
  }
  cout << dp[s.size()];

  return 0;
}
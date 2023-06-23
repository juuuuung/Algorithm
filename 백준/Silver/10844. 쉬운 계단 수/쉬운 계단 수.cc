#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
long long d[101][10];

int main(){
  init();
  cin >> n;
  for(int i = 1; i <= 9; ++i) d[1][i] = 1;

  for(int i = 2; i <= n; ++i){
    for(int j = 0; j <= 9; ++j){
      if(j == 0) d[i][j] = d[i-1][j+1];
      else if(j == 9) d[i][j] = d[i-1][j-1];
      else d[i][j] = d[i-1][j-1] + d[i-1][j+1];
      d[i][j] %= 1'000'000'000;
    }
  }

  unsigned long long ans = 0;
  for(int i = 0; i <= 9; ++i)
    ans = (ans + d[n][i]) % 1'000'000'000;
  cout << ans;
  return 0;
}
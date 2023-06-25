#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, k, cnt = 0;
int coin[12];

int main(){
  init();
  cin >> n >> k;
  for(int i = 1; i <= n; ++i)
    cin >> coin[i];
  
  for(int i = n; i > 0; --i){
    if(coin[i] <= k){
      cnt += k/coin[i];
      k -= (k/coin[i]) * coin[i];
    }
  }
  cout << cnt;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int tc, Max = 100'000;
int main(){
  init();
  cin >> tc;
  while(tc--){
    int num;
    cin >> num;
    for(int i = 2; i <= Max; ++i){
      int cnt = 0;
      while(num%i == 0){
        cnt++; num/=i;
      }
      if(cnt) cout << i << ' ' << cnt << '\n';
      if(num == 1)break;
    }
  }
  return 0;
}
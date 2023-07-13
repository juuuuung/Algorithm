#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main(){
  init();
  int cnt = 1;
  while(true){
    int l, p, v, ans = 0;
    cin >> l >> p >> v;
    if(l == 0 && p == 0 && v == 0)break;
    ans += ((v/p) * l) + min(v%p, l);
    cout <<"Case " <<cnt << ": "<< ans << '\n';
    ans = 0;cnt++;
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, ans = 0, cnt = 1;
int main(){
  init();
  cin >> n;
  if(n == 0){
    cout << 0;
    return 0;
  }
  for(int i = 1; i <= n; ++i){
    cnt *= i;
    string cpy = to_string(cnt);
    for(int j = cpy.size()-1; j > -1; --j){
      if(cpy[j] == '0') ans++;
      else{
        cnt = cpy[j]-'0';
        if(i >= 10) cnt = (cpy[j-1]-'0') * 10 + (cpy[j]-'0');
        if(i >= 100) cnt = (cpy[j-2]-'0') * 100 + (cpy[j-1]-'0') * 10 + (cpy[j]-'0'); 
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
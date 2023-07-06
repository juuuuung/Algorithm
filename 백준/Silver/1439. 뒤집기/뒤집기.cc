#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
string s;
int cnt = 0;
int main(){
  init();
  cin >> s;
  int size = s.size();
  for(int i = 1; i < size; ++i){
    if(s[i-1] == '0' && s[i] == '1') cnt++;
    if(i == size-1 && s[i] == '0') cnt++;
  }
  if(s[size-1] == '0' && s[0] == '0') cnt = min(cnt, cnt-1);
  else if(s[size-1] == '1' && s[0] == '1')cnt = min(cnt, cnt + 1);

  cout << cnt;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n;
int main(){
  init();
  cin >> n;
  int cnt = 0;
  int i = 666;

  while(cnt != n){
    string s = to_string(i);
    for(int j = 0; j < s.length()-2; ++j){
      if(s[j]=='6' && s[j+1]=='6' && s[j+2] == '6'){
        cnt++;
        break;
      }
    }
    i++;
  }
  cout << i-1;
  return 0;
}
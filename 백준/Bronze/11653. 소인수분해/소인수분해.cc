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

  int cpy = n;
  for(int i= 2; i <= n; ++i){
    while(cpy%i==0){
      cout << i << '\n';
      cpy/= i;
    }
    if(cpy == 1)break;
  }
  return 0;
}
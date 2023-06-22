#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

unsigned long long d[91];

int main(){
  init();
  int n;
  cin >> n;
  if(n == 1 || n== 2){
    cout << 1;
    return 0;
  }
  d[1] = 1;d[2] = 1;d[3] = 2;
  for(int i =4; i <= n; ++i){
    d[i] = d[i-1] + d[i-2];
  }
  cout << d[n];
  return 0;
}
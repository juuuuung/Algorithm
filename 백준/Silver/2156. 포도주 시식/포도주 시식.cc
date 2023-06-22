// 포도주 시식
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
int a[10001];
long long d[10001];

int main(){
  init();
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  d[1] = a[1];
  d[2] = a[2] + a[1];
  for(int i = 3; i <= n; ++i){
    d[i] = max({d[i-3] + a[i-1] + a[i], d[i-2] + a[i], d[i-1]});
  }
  cout << d[n];
  return 0;
}
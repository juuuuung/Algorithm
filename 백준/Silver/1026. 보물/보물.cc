#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, ans = 0;
int a[102], b[102];

bool comp(int i, int j){
  return i > j;
}

int main(){
  init();
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];
  sort(a, a+n);
  sort(b, b+n, comp);
  for(int i= 0; i < n; ++i)ans += (a[i] * b[i]);
  cout << ans;

  return 0;
}
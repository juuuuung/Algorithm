#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int gcd(int m, int n){
  if(n == 0)return m;
  return gcd(n, m%n);
}
int tc, n;
int numArr[102];
int main(){
  init();
  cin >> tc;
  while(tc--){
    long long ans = 0;
    cin >> n;
    for(int i= 0; i < n; ++i) cin >> numArr[i];
    for(int i= 0; i < n-1; ++i)
      for(int j = i+1; j < n; ++j)
        ans += (numArr[i] > numArr[j]?gcd(numArr[i], numArr[j]) : gcd(numArr[j], numArr[i]));
    cout << ans << '\n';
  }
  return 0;
}
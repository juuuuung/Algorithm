#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

//최대 공약수
int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}
//최소 공배수
int lcm(int a, int b){
  return a / gcd(a, b) * b;
}
int solved(int m, int n, int x, int y){
  if(x == m) x = 0;
  if(y == n) y = 0;
  int l = lcm(m, n);
  for(int i = x; i <= l; i+=m){
    if(i == 0) continue;
    if(i % n == y) return i;
  }
  return -1;
}
int tc;
int main(){
  init();
  cin >> tc;
  while(tc--){
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    cout << solved(m, n, x, y) << '\n';
  }
  return 0;
}
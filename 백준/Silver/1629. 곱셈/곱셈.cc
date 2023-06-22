#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
using ll = long long;

ll POW(int a, int b, int m){
  if(b == 1) return a % m;
  ll val = POW(a, b/2, m);
  val = val * val % m;
  if(b%2 == 0) return val%m;
  else return val%m * a%m;
}

int main()
{
  init();
  ll a,b,m;
  cin >> a >> b >> m;
  cout << POW(a, b, m);
  return 0;
}
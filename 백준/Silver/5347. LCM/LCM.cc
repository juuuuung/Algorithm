#include <bits/stdc++.h>
typedef unsigned long long int uli;

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int tc;
uli gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}
uli lcm(int a, int b){
  return a / gcd(a, b) * b;
}
int main(){
  init();
  cin >> tc;
  while(tc--){
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
  }
  return 0;
}
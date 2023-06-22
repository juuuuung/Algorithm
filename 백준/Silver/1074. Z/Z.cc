// 재귀 - Z
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int z(int n, int r, int c){
  if(n == 0) return 0;
  int half = (1<<(n-1));
  if(r < half && c < half)return z(n-1, r, c);
  if(r < half && c >= half)return half*half + z(n-1, r, c-half);
  if(r >=half && c < half)return 2*half*half + z(n-1, r-half, c);
  if(r >= half && c >= half) return 3*half*half + z(n-1, r-half, c-half);
}

int main()
{
  init();
  int n, r, c;
  cin >> n >> r >> c;
  cout << z(n, r, c);
  return 0;
}
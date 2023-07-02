#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n;
vector<pair<int, int>> v;

int main(){
  init();
  cin >> n;
  for(int i = 0; i < n; ++i){
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    v.push_back({m1*100+d1, m2*100+d2});
  }
  int ans = 0;
  int t = 301;
  while(t < 1201){
    int nxt = t;
    for(int i= 0; i < n; ++i)
      if(v[i].X <= t && v[i].Y > nxt)
        nxt = v[i].Y;
    if(nxt == t){
      cout << 0;
      return 0; 
    }
    ans++;
    t = nxt;
  }
  cout << ans;
  return 0;
}
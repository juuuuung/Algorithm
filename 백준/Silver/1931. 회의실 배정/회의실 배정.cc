#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, cnt = 0;
vector<pair<int, int>> v;

int main(){
  init();
  cin >> n;
  for(int i = 0; i < n; ++i){
    int i1, i2;
    cin >> i1 >> i2;
    v.push_back({i2, i1});
  }

  sort(v.begin(), v.end());

  int t = 0;
  for(int i = 0; i < n; ++i){
    if(t > v[i].second) continue;
    cnt++;
    t = v[i].first;
  }
  cout << cnt;

  return 0;
}
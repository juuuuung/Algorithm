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
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  int pivot = v[0].Y;
  unsigned long long cnt = abs(v[0].X-v[0].Y);
  for(int i = 1; i < v.size(); ++i){
    if(v[i].X <= pivot && v[i].Y > pivot){
      cnt += abs(pivot - v[i].Y);
      pivot = v[i].Y;
    }
    else if(v[i].X > pivot){
      cnt += abs(v[i].X - v[i].Y);
      pivot = v[i].Y;
    }
  }
  cout << cnt << '\n';
  return 0;
}
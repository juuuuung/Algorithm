#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}


int main()
{
  init();
  int n,m,j,ans = 0,idx;
  cin >> n >> m;
  deque<int> d;
  for(int i =1; i < n+1; ++i)d.push_back(i);
  while(m--){
    cin >> j;
    if(d[0] == j)d.pop_front();
    else{
      for(int i=0; i < d.size(); ++i){
        if(j == d[i]){idx = i; break;}
      }
      while(idx != 0&&idx <= ceil(d.size()/2)){ // 찾은 인덱스 가 반인덱스 보다 작다면 (왼쪽이동)
        d.push_back(d.front());
        d.pop_front();
        --idx;
        ++ans;
      }
      while(idx != 0&&idx > ceil(d.size()/2)){
        d.push_front(d.back());
        d.pop_back();
        idx = (idx + 1) % d.size();
        ++ans;
      }
      d.pop_front();
    }
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
long long cnt = 0;
stack<pair<int, int>> s;

int main(){
  init();
  cin >> n;
  while(n--){
    int now; cin >> now;
    int same = 1;
    while(!s.empty() && s.top().first < now){
      cnt += s.top().second;
      s.pop();
    }
    if(!s.empty()){
      if(s.top().first == now){
        cnt += s.top().second;
        same = s.top().second +1;
        s.pop();
        if(s.size() > 0)cnt++;
      }
      else{
        cnt++;
      }
    }
    s.push({now, same});
  }

  cout << cnt;

  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, k, board[100'002], dist[100'002];
queue<pair<int, int>> Q;
stack<int> order;

int main(){
  init();
  cin >> n >> k;
  memset(dist, -1, sizeof(dist));

  Q.push({n, 0});
  dist[n] = 0;

  while(!Q.empty()){
    int x, cnt;
    tie(x, cnt) = Q.front(); Q.pop();
    if(x == k){
      cout << cnt << '\n';
      if(cnt != 0) order.push(k);
      while(x != n){
        x = dist[x];
        if(x == n) break;
        order.push(x);
      }
      order.push(n);

      while(!order.empty()){
        cout << order.top() << " ";
        order.pop();
      }
      return 0;
    }
    if(x+1 <= 100'000 && dist[x+1] == -1){
      Q.push({x+1, cnt+1});
      dist[x+1] = x;
    }
    if(x-1 >= 0 && dist[x-1] == -1){
      Q.push({x-1, cnt+1});
      dist[x-1] = x;
    }
    if(x*2 <= 100'000 && dist[x*2] == -1){
      Q.push({x*2, cnt+1});
      dist[x*2] = x;
    }

  }
  return 0;
}
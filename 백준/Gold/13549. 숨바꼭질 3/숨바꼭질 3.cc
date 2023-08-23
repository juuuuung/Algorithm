#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, k, dist[100'002];
queue<int> Q;
bool OOB(int x){
  return x < 0 || x > 100'000;
}
int main(){
  init();
  cin >> n >> k;
  memset(dist, -1, sizeof(dist));
  Q.push(n);
  dist[n] = 0;
  while(!Q.empty()){
    int x = Q.front(); Q.pop();
    if(not OOB(x-1) && (dist[x-1] == -1 ||dist[x-1] > dist[x]+1)){
      Q.push(x-1);
      dist[x-1] = dist[x] + 1;
    }
    if(not OOB(x+1) && (dist[x+1] == -1 || dist[x+1] > dist[x]+1)){
      Q.push(x+1);
      dist[x+1] = dist[x] + 1;
    }
    if(not OOB(x*2) && (dist[x*2] == -1 || dist[x*2] > dist[x])){
      Q.push(x*2);  
      dist[x*2] = dist[x];
    } 
  }
  cout << dist[k];
  return 0;
}
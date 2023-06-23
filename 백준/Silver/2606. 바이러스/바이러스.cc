#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
vector<int> network[102];
int dist[102] = {1,};
int cnt = 0;

void dfs(int x){
    dist[x] = 1;
    for(int i = 0; i < network[x].size(); ++i){
      if(!dist[network[x][i]]){
        cnt++;
        dfs(network[x][i]);
      }
    }
}

int main(){
  init();
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    network[a].push_back(b);
    network[b].push_back(a);
  }
  
  dfs(1);
  cout << cnt;

  return 0;
}
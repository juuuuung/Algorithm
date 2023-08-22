#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int T, p[100'002];
int sp = 100'002, cp = 100'010, teamCnt;
bool baseFine = false;

vector<int> vis(100'002);
stack<int> S;

void dfs(){
  cp = S.top();
  int nx = p[cp];
  vis[cp] = 1;

  if(vis[nx] == 0){
    S.push(nx);
    dfs();
  }else if(vis[nx] == 1){
    sp = nx;
    baseFine = true;
  }
  cp = S.top();

  if(baseFine && sp != cp){
    teamCnt++;
  }else if(baseFine && sp == cp){
    teamCnt++;
    baseFine = false;
  }
  vis[cp] = 2;
  return S.pop();
}

int main(){
  init();
  cin >> T;
  while(T--){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i){
      if(!vis[i]){
        S.push(i);
        dfs();
        sp = 100'002, cp = 100'010;
      }
    }
    cout << n-teamCnt << '\n';
    fill(vis.begin(), vis.begin()+n+1, 0);
    teamCnt = 0;
  }
  return 0;
}
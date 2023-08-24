#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n,m,k,board[1002][1002],vis[1002][1002][11] = {0,}, ans = 2'000'000'000;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

// timeState {true : 낮, false: 밤}
// stay {true: 전에 멈췄었던 상태, false: 전에 멈춰있지 않았던 상태}
// x, y, timeState, stay, destoryCnt, walkCnt
queue<tuple<int,int,bool,bool,int,int>> Q;

bool OOB(int x, int y){
  return x <= 0 || x > n || y <= 0 || y > m;
}

int main(){
  init();
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i){
      string s;
      cin >> s;
      for(int j = 1; j <= m; ++j){
        board[i][j] = (s[j-1] - '0');
      }
  }
  memset(vis, 0, sizeof(vis));
  
  Q.push({1,1,true,false,0,1});
  vis[1][1][0] = 1;

  while(!Q.empty()){
    int x, y, destroyCnt, walkCnt;
    bool timeState, stay;
    tie(x, y, timeState, stay, destroyCnt, walkCnt) = Q.front(); Q.pop();
    if(x == n && y == m){
      ans = min(ans, walkCnt);
      continue;
    }
    if(stay){
      for(int dir = 0; dir < 4; ++dir){
        int nx = x + dx[dir], ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(!board[nx][ny] || vis[nx][ny][destroyCnt] || vis[nx][ny][destroyCnt+1]) continue;
        Q.push({nx, ny, !timeState, false, destroyCnt+1, walkCnt+1});
        vis[nx][ny][destroyCnt+1] = 1;
      }
      continue;
    }
    for(int dir = 0; dir < 4; ++dir){
      int nx = x + dx[dir], ny = y + dy[dir];
      if(OOB(nx, ny))continue;
      if(vis[nx][ny][destroyCnt]) continue;
      if(board[nx][ny] && destroyCnt < k){
        if(timeState && !vis[nx][ny][destroyCnt+1]){
          Q.push({nx, ny, !timeState, false, destroyCnt+1, walkCnt+1});
          vis[nx][ny][destroyCnt+1] = 1;
        }else{
          Q.push({x, y, !timeState, true, destroyCnt, walkCnt+1});
        }
        continue; 
      }
      if(!board[nx][ny]) {
        Q.push({nx, ny, !timeState, stay, destroyCnt, walkCnt+1});
        vis[nx][ny][destroyCnt] = 1;
      }
    }
  }

  if(ans == 2'000'000'000) cout << -1;
  else cout << ans;
  return 0;
}
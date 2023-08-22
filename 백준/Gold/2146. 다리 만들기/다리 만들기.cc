#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int N, board[102][102], vis[102][102], isLandCnt = 1;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<pair<int, int>> isLandQ;

bool OOB(int x, int y){
  return x < 0 || x >= N || y < 0 || y >= N;
}

int bfs(int localIsland){
  while(!isLandQ.empty()){
    int x, y; tie(x, y) = isLandQ.front(); isLandQ.pop();
    for(short dir = 0; dir < 4; ++dir){
      int nx = x + dx[dir], ny = y + dy[dir];
      if(OOB(nx, ny)) continue;
      if(vis[nx][ny] >= 0 || board[nx][ny] == localIsland) continue;
      if(board[nx][ny] > 0){
        return vis[x][y];
      }
      isLandQ.push({nx, ny});
      vis[nx][ny] = vis[x][y] + 1;
    }
  }
  return 2'000'000'000;
}

bool findZero(int x, int y){
  for(int dir = 0; dir < 4; ++dir){
    int nx = x+dx[dir], ny = y+dy[dir];
    if(OOB(nx, ny))continue;
    if(board[nx][ny] == 0) return true;
  }
  return false;
}

int main(){
  init();
  memset(vis, -1, sizeof(vis));
  cin >> N;
  for(int i =0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      cin >> board[i][j];

  int ans = 2'000'000'000;

  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(board[i][j] == 1){
        ++isLandCnt;
        isLandQ.push({i, j});
        board[i][j] = isLandCnt;
        while(!isLandQ.empty()){
          int x, y; 
          tie(x, y) = isLandQ.front(); isLandQ.pop();
          for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] != 1) continue;
            isLandQ.push({nx, ny});
            board[nx][ny] = isLandCnt;
          }
        }
      }
      if(board[i][j] > 1 && findZero(i, j)){
        isLandQ.push({i,j});
        vis[i][j] = 0;
        ans = min(ans, bfs(board[i][j]));
        memset(vis, -1, sizeof(vis));
        isLandQ = queue<pair<int, int>>();
      }
    }
  }
  cout << ans;
  return 0;
}
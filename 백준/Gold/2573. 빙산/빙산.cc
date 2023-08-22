#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int N, M;
int board[302][302], sub[302][302];
bool vis[302][302];

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
queue<pair<int, int>> Q;

bool OOB(int x, int y){
  return (x < 0 || x >= N || y < 0 || y >= M);
}

void substract(){
  for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
      if(board[i][j]){
        int result = board[i][j] - sub[i][j];
        board[i][j] = result <= 0 ? 0 : result;
      }
    }
  }
}

int main(){
  init();
  cin >> N >> M;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < M; ++j)
      cin >> board[i][j];
  
  int year = 0, lumpCnt = 1;
  while(lumpCnt < 2){
    bool existence = false;
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < M; ++j){
        if(board[i][j]){
          existence = true;
          int zeroCnt = 0;
          for(int dir = 0; dir < 4; ++dir)
            zeroCnt += (board[i+dx[dir]][j+dy[dir]] == 0);
          sub[i][j] = zeroCnt;
        }
      }
    }

    if(!existence){
      cout << 0;
      return 0;
    }
    substract();

    lumpCnt = 0;

    for(int i=0; i<N; ++i){
      for(int j=0; j<M; ++j){
        if(board[i][j] && !vis[i][j]){
          lumpCnt++;
          Q.push({i, j});
          vis[i][j] = 1;
          while(!Q.empty()){
            int x, y; tie(x, y) = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; ++dir){
              int nx = dx[dir] + x;
              int ny = dy[dir] + y;
              if(OOB(nx, ny) || vis[nx][ny] || !board[nx][ny]) continue;
              Q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
      }
    }
    memset(vis, 0, 301*301);
    ++year;
  }
  cout << year;
  return 0;
}
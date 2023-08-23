#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int k, w, h, board[202][202], dist[202][202][31];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int hdx[8] = {-1,-2,-2,-1,1,2,2,1}, hdy[8] = {-2,-1,1,2,2,1,-1,-2};

// x, y, kCnt
queue<tuple<int, int, int>> Q;

bool OOB(int x, int y){
  return x < 0 || x >= h || y < 0 || y >= w;
}

int main(){
  init();
  cin >> k >> w >> h;
  for(int i = 0; i < h; ++i)
    for(int j = 0; j < w; ++j)
      cin >> board[i][j];

  memset(dist, -1, sizeof(dist));

  Q.push({0,0,0});
  dist[0][0][0] = 0;
  while(!Q.empty()){
    int x, y, kcnt;
    tie(x, y, kcnt) = Q.front();Q.pop();
    if(kcnt < k){
      for(int dir = 0; dir < 8; ++dir){
        int nx = x+hdx[dir], ny = y+hdy[dir];
        if(OOB(nx, ny))continue;
        if(dist[nx][ny][kcnt+1] >= 0 || board[nx][ny] == 1) continue;
        Q.push({nx, ny, kcnt+1});
        dist[nx][ny][kcnt+1] = dist[x][y][kcnt]+1;
      }
    }
    for(int dir = 0; dir < 4; ++dir){
      int nx = x+dx[dir], ny = y+dy[dir];
      if(OOB(nx, ny))continue;
      if(dist[nx][ny][kcnt] >= 0 || board[nx][ny] == 1) continue;
      Q.push({nx, ny, kcnt});
      dist[nx][ny][kcnt] = dist[x][y][kcnt]+1;
    }
  }

  int min_ans = 2'000'000'000;
  
  for(int l = 0; l <=k; ++l){
    if(dist[h-1][w-1][l] == -1) continue;
    min_ans = min(min_ans, dist[h-1][w-1][l]);
  }

  if(min_ans == 2'000'000'000) cout << -1;
  else cout << min_ans;
  return 0;
}
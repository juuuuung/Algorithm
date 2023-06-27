#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, t = 0;

int board[22][22], dist[22][22];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<tuple<int, int, int>> q;

int baby = 2;
int growing = 0;

int main(){
  init();
  cin >> n;
  memset(dist, -1, 22 * 22 * sizeof(int));
  for(int i= 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> board[i][j];
      if(board[i][j] == 9){
        q.push({i, j, 0});
        dist[i][j] = 0;
      }
    }
  }

  while(1){
    while(!q.empty()){
      int x, y, cnt; tie(x, y, cnt) = q.front(); q.pop();
      int nxtCnt = cnt + 1;
      for(int dir = 0; dir < 4; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(dist[nx][ny] > -1 || board[nx][ny] > baby)continue;

        q.push({nx, ny, nxtCnt});
        dist[nx][ny] = (board[nx][ny] == baby ? 1000 : nxtCnt);
      }
    }
    int mins = 1000;
    int x, y;
    for(int i= 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(board[i][j] == 9)
          board[i][j] = 0;
        else if(board[i][j] > 0 && dist[i][j] != -1 && mins > dist[i][j]){
          mins = dist[i][j];
          x = i; y = j;
        }
      }
    }
    if(mins != 1000){
      t += dist[x][y];
      board[x][y] = 9;
      q.push({x, y, 0});
      growing++;
      if(growing == baby){baby++;growing = 0;}
      memset(dist, -1, 22 * 22 * sizeof(int));
      dist[x][y] = 0;
    } else{
      cout << t << '\n';
      return 0;
    }
  }
  return 0;
}
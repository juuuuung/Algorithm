#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
int dist[11][11][11][11];
string board[11];

pair<int, int> red, blue;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int bfs(){
  queue<tuple<int, int, int, int>> Q;
  Q.push({red.X, red.Y, blue.X, blue.Y});
  dist[red.X][red.Y][blue.X][blue.Y] = 0;
  while(!Q.empty()){
    int rx, ry, bx, by;
    tie(rx, ry, bx, by) = Q.front(); Q.pop();
    int cnt = dist[rx][ry][bx][by];
    if(cnt >= 10)return -1;
    for(int dir = 0; dir < 4; ++dir){
      int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;
      while(board[n_bx + dx[dir]][n_by + dy[dir]] == '.'){
        n_bx += dx[dir];
        n_by += dy[dir];
      }
      if(board[n_bx + dx[dir]][n_by+dy[dir]] == 'O')continue;

      while(board[n_rx + dx[dir]][n_ry+dy[dir]] == '.'){
        n_rx += dx[dir];
        n_ry += dy[dir];
      }
      if(board[n_rx+dx[dir]][n_ry+dy[dir]] == 'O')return cnt+1;

      if((n_rx == n_bx) && (n_ry == n_by)){
        if(dir == 0) (rx > bx) ? n_bx-- : n_rx--;
        else if(dir == 1) (ry > by) ? n_by-- : n_ry--;
        else if(dir == 2) (rx > bx) ? n_rx++ : n_bx++;
        else if(dir == 3) (ry > by) ? n_ry++ : n_by++;
      }

      if(dist[n_rx][n_ry][n_bx][n_by] != -1)continue;
      dist[n_rx][n_ry][n_bx][n_by] = cnt+1;
      Q.push({n_rx, n_ry, n_bx, n_by});
    }
  }
  return -1;
}

int main()
{
  init();

  for(int i =0; i < 10; ++i)
    for(int j =0;j < 10; ++j)
      for(int k = 0; k < 10; ++k)
        fill(dist[i][j][k], dist[i][j][k]+10, -1);
  
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> board[i];
    for(int j =0; j < m; ++j){
      if(board[i][j] == 'R'){
        red = {i, j};
        board[i][j] = '.';
      }
      else if(board[i][j] == 'B'){
        blue = {i, j};
        board[i][j] = '.';
      }
    }
  }
  cout << bfs();
  return 0;
}
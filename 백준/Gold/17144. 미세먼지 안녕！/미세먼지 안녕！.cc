#include <bits/stdc++.h>
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int R, C, k;
int board[52][52];

int robot[2];
queue<tuple<int, int, int>> dust;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int x, int y, int less, int unless){
  return x < unless || x > less || y < 1 || y > C;
}

int main(){
  init();
  cin >> R >> C >> k;
  int cur = 0;
  for(int i =1; i <= R; ++i){
    for(int j =1; j <= C; ++j){
      cin >> board[i][j];
      if(board[i][j] > 0)
        dust.push({i, j, board[i][j]});
      else if(board[i][j] == -1)
        robot[cur++] = i;
    }
  }

  for(int u = 0; u < k; ++u){
    while(!dust.empty()){
      int x, y, amount;
      tie(x, y, amount) = dust.front(); dust.pop();
      int nxtAmount = amount / 5;
      int cnt = 0;
      for(int dir = 0; dir < 4; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny, R, 1)) continue;
        if(board[nx][ny] == -1) continue;
        cnt++;
        board[nx][ny] += nxtAmount;
      }
      board[x][y] -= amount;
      board[x][y] += amount -(amount/5) * cnt;
    }
    
    int x = robot[0] == 1? robot[0] : robot[0] - 1, y = robot[0] == 1? 2: 1;
    for(int dir = 0; dir < 4; ++dir){
      int nx = x, ny = y;
      while(!OOB(x + dx[dir], y + dy[dir], robot[0], 1)){
        nx += dx[dir]; ny += dy[dir];
        board[x][y] = board[nx][ny];
        if(board[nx][ny] == -1)board[x][y]=0;
        x = nx; y = ny;
      }
    }
    x = robot[1] == R ? robot[1] : robot[1] + 1, y = robot[1] == R ? 2 : 1;
    for(int dir = 6; dir > 2; --dir){
      int nx = x, ny = y;
      while(!OOB(x + dx[dir%4], y + dy[dir%4], R, robot[1])){
        nx += dx[dir%4]; ny += dy[dir%4];
        board[x][y] = board[nx][ny];
        if(board[nx][ny] == -1)board[x][y]=0;
        x = nx; y = ny;
      }
    }
    for(int i = 1; i <= R; ++i)
      for(int j =1; j <= C; ++j)
        if(board[i][j] > 0)
          dust.push({i, j, board[i][j]});
  }

  int ans = 2;
  for(int i =1; i <= R; ++i)
    for(int j = 1; j <= C; ++j)
      ans += board[i][j];
  cout << ans;


  return 0;
}
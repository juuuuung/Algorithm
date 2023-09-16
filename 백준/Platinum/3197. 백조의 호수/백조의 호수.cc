#include <bits/stdc++.h>
#define MAX 1511
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int r, c, cnt = 0, sx, sy;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[MAX][MAX];
bool svis[MAX][MAX], bvis[MAX][MAX];
queue<pair<int, int>> Q,Q2,S, S2;

bool OOB(int nx, int ny){
  return nx<0||nx>=r||ny<0||ny>=c;
}

int main(){
  init();
  cin >> r >> c;
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      cin >> board[i][j];
      if(board[i][j] == 'L') sx = i, sy = j; 
      if(board[i][j] != 'X') Q.push({i, j}); 
    }
  }

  S.push({sx, sy});
  svis[sx][sy] = 1;
  bool isPossible = false;
  while(!isPossible){
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        bvis[cur.X][cur.Y] = 1;
        for(int dir = 0; dir < 4; ++dir){
          int nx = cur.X+dx[dir], ny=cur.Y+dy[dir];
          if(OOB(nx, ny) || bvis[nx][ny])continue;

          if(board[nx][ny] == 'X')Q2.push({nx, ny});
          bvis[nx][ny] = 1;
        }
    }
    while(!Q2.empty()){
        auto cur = Q2.front(); Q2.pop();
        board[cur.X][cur.Y] = '.';
        Q.push({cur.X, cur.Y});
    }
    cnt++;

    while(!S.empty()){
      auto cur = S.front(); S.pop();
      for(int dir = 0; dir < 4; ++dir){
        int nx = cur.X+dx[dir], ny = cur.Y+dy[dir];
        if(OOB(nx, ny) || svis[nx][ny] ) continue;
        if(board[nx][ny] == 'L'){
          isPossible = true;
          break;  
        }
        if(board[nx][ny] == 'X'){
          S2.push({nx, ny});
          svis[nx][ny] = 1;
          continue;
        }
        S.push({nx, ny});
        svis[nx][ny] = 1;
      }
    }
    while(!S2.empty()){
      auto cur = S2.front(); S2.pop();
      S.push({cur.X, cur.Y});
    } 
  }
  cout << cnt;
  return 0;
}
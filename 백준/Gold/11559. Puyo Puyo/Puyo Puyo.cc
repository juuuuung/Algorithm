#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

char board[13][7];
bool vis[13][7], isPuyo;
int row = 12, col = 6, totalCnt = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void visreset(){
  for(int i =0; i < row; ++i)
    for(int j =0; j < col; ++j)
      vis[i][j] = false;
}

bool OOB(int x, int y){
  return x < 0 || x >= row || y < 0 || y >= col;
}

void tilted(){
  for(int i =0; i < col; ++i){
    char tmp[13] = "............";
    int cur = 0;
    for(int j =row-1; j > -1; --j){
      if(board[j][i] == '\0')continue;
      if(board[j][i] == '.')continue;
      tmp[cur++] = board[j][i];
    }
    for(int j = row-1; j > -1; --j){
      board[j][i] = tmp[row - 1 - j]; 
    }
  }
  
}

void bfs(int x, int y){
  queue<pair<int, int>> Q;
  vector<pair<int,int>> V;

  Q.push({x, y});
  vis[x][y] = 1;
  V.push_back({x, y});

  char color = board[x][y];

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir<4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(OOB(nx, ny) || board[nx][ny] == '.' || color != board[nx][ny] || vis[nx][ny]) continue;
      Q.push({nx, ny}); V.push_back({nx, ny});
      vis[nx][ny] = 1;
    }
  }
  if(V.size() >= 4){
    isPuyo = true;
    for(auto i : V)
      board[i.X][i.Y] = '.';
      visreset();
  }
}

int main()
{
  init();
  for(int i =0; i < row; ++i)cin >> board[i];

  do{
    isPuyo = false;
    tilted();
    for(int i =0; i < row; ++i){
      for(int j =0; j < col; ++j){
        if(board[i][j] != '.' && !vis[i][j]){
          bfs(i, j);
        }
      }
    }
    if(isPuyo) ++totalCnt;
    visreset();
  }while(isPuyo);
  cout << totalCnt;
  return 0;
}
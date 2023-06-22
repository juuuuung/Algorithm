#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int vis[1001][1001][2];
char board[1001][1001];

int n, m;

int bfs(){
  for(int i = 0; i < n; ++i)
    for(int j =0; j < m; ++j)
      vis[i][j][0] = vis[i][j][1] = -1;
  vis[0][0][0] = vis[0][0][1] = 1;
  queue<tuple<int, int, int>> Q;
  Q.push({0,0,0});
  while(!Q.empty()){
    int x, y, broke;
    tie(x, y, broke) = Q.front();
    if(x == n-1 && y == m-1){return vis[x][y][broke];}
    Q.pop();
    int nxtIdx = vis[x][y][broke] + 1;
    for(int dir = 0; dir < 4; ++dir){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx<0||nx>=n||ny<0||ny>=m)continue;
      if(board[nx][ny] == '0' && vis[nx][ny][broke] == -1){
        vis[nx][ny][broke] = nxtIdx;
        Q.push({nx,ny,broke});
      }
      if(!broke && board[nx][ny] == '1' && vis[nx][ny][1] == -1){
        vis[nx][ny][1] = nxtIdx;
        Q.push({nx, ny, 1});
      }
    }
  }
  return -1;
}

int main()
{
  init();
  cin >> n >> m;
  for(int i =0; i < n; ++i)
    for(int j =0; j < m; ++j)
      cin >> board[i][j];
  cout << bfs();
  return 0;
}

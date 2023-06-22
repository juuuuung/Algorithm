// 유기농 배추 - BFS
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool board[51][51],vis[51][51];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int tc, m, n, k;
queue<pair<int,int>> Q;

void BFS(int x, int y){
  Q.push({x, y});
  vis[x][y] = 1;
  while(!Q.empty()){
    pair<int, int> cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx<0||nx>=n||ny<0||ny>=m)continue;
      if( vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int main()
{
  init();
  cin >> tc;
  while(tc--){
    cin >> m >> n >> k;
    int x, y;
    for(int i = 0; i < k; ++i){
      cin >> x >> y;
      board[y][x] = 1;
    }
    int len = 0;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(board[i][j] == 1 && !vis[i][j]){
          BFS(i, j);
          ++len;
        }
      }
    }
    cout << len << '\n';
    for(int i = 0; i < n; ++i){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, 0);
    }
  }
  return 0;
}
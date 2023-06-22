#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string board[102];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int n,m;
queue<pair<int, int>> Q;

void BFS(){
  while(!Q.empty()){
    pair <int, int> cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
      if(vis[nx][ny] >= 0 || board[nx][ny] != '1')continue;
      vis[nx][ny] = vis[cur.X][cur.Y]+1;
      Q.push({nx, ny});
    }
  }
}

int main()
{
  init();
  cin >> n >> m;
  for(int i =0; i < n; ++i) cin >> board[i];
  for(int i = 0; i <n; ++i ) fill(vis[i], vis[i]+m,-1);

  Q.push({0,0});
  vis[0][0] = 0;
  BFS();
  cout << vis[n-1][m-1]+1;
  return 0;
}
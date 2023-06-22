//미로 탈출 홍익이와 마녀
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
int hx, hy, ex, ey;

int board[1001][1001];
int dist[1001][1001][2];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<tuple<int, int, int>> Q;

bool OOB(int x, int y){
  return x < 1 || x > n || y < 1 || y > m;
}

int main(){
  init();
  cin >> n >> m;
  cin >> hx >> hy >> ex >> ey;

  for(int i =0; i <= n; ++i)
    for(int j =0; j <= m; ++j)
      for(int k =0; k < 2; ++k)
        dist[i][j][k] = -1;

  for(int i = 1; i <= n; ++i)
    for(int j =1; j <= m; ++j)
      cin >> board[i][j];
  
  Q.push({hx, hy, 0});
  dist[hx][hy][0] = 0; //행렬 은 1행 1열 이렇게 나타냄 0행 0열 없음
  while(!Q.empty()){
    int x, y, st;
    tie(x, y, st) = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx == ex && ny == ey){
        cout << dist[x][y][st] + 1 << '\n';
        return 0;
      }
      if(OOB(nx, ny) || dist[nx][ny][st] != -1)continue;
      if(st == 0 && board[nx][ny] == 1){
        Q.push({nx, ny, 1});
        dist[nx][ny][1] = dist[x][y][st] + 1;
        continue;
      }
      if(board[nx][ny] == 1)continue;
      Q.push({nx, ny, st});
      dist[nx][ny][st] = dist[x][y][st] + 1;
    }
  }
  cout << -1;
  return 0;
}
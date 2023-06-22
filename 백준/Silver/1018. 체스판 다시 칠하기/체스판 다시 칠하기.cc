#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m, ans = 2'000'000'000;

string board[51];
char board2[9][9];
bool dist[9][9];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool OOB(int nx, int ny){
  return nx < 0 || nx >= 8 || ny < 0 || ny >= 8;
}

int bfs(int i, int j, char c){
  for(int k = 0; k < 8; ++k)
    for(int w = 0; w < 8; ++w)
      board2[k][w] = board[i + k][j + w];

  int cnt = (board2[0][0] != c)?1 : 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 1;
  board2[0][0] = c;

  while(!q.empty()){
    int x, y;
    tie(x, y) = q.front(); q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = x+dx[dir];
      int ny = y+dy[dir];
      if(OOB(nx, ny) || dist[nx][ny])continue;
      if(board2[x][y] == board2[nx][ny]){
        board2[nx][ny] = (board2[x][y] == 'B')? 'W' : 'B';
        cnt++;
      }
      q.push({nx, ny});
      dist[nx][ny] = 1;
    }
  }
  memset(dist, 0, 9*9*sizeof(bool));
  return cnt;
}

int main(){
  init();
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> board[i];
  
  for(int i = 0; i <= n-8; ++i)
    for(int j = 0; j <= m-8; ++j)
      ans = min({ans, bfs(i, j, 'W'), bfs(i, j, 'B')});
      
  cout << ans;
  return 0;
}
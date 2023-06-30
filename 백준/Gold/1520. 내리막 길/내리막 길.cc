#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
int board[501][501];
int dp[501][501];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y){
  if(dp[x][y] != -1)return dp[x][y];
  if(x == n-1 && y == m-1) return 1;
  dp[x][y] = 0;
  for(int dir = 0; dir < 4; ++dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
    if(board[x][y] > board[nx][ny]) dp[x][y] += dfs(nx, ny);
  }
  return dp[x][y];
}

int main(){
  init();
  cin >> n >> m;
  for(int i= 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> board[i][j];
      dp[i][j] = -1;
    }
  }
  cout << dfs(0, 0);
  return 0;
}
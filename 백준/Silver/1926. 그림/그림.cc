// BFS - 그림 문제
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool board[501][501], vis[501][501];
int n, m, picSize = 0, picNum = 0, MAX = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

void BFS(){
  picSize = 0;
  ++picNum;
  while(!Q.empty()){
    pair<int, int> cur = Q.front(); Q.pop();
    // cout << '(' << cur.X << ", " << cur.Y << ") => " << '\n';
    ++picSize;
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  if(picSize > MAX) MAX = picSize;
  MAX = (picSize > MAX) ? picSize : MAX; 
}

int main()
{
  init();
  bool str;
  cin >> n >> m;
  // 배열 초기화
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> str;
      board[i][j] = str;
    }
  }

  // board 배열 순회
  for(int i =0; i < n; ++i){
    for(int j =0; j < m; ++j){
      if(board[i][j] == 1 && vis[i][j] == 0){
        Q.push({i,j});
        vis[i][j] = 1;
        BFS();
      }
    }
  }
  cout << picNum << '\n' << MAX << '\n';

  return 0;
}
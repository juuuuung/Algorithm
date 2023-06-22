// bfs - 불 2 골드 4
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int h,w,fvis[1001][1001], pvis[1001][1001],dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int board[1001][1001];

int main()
{
  init();
  int tc;
  cin >> tc;
  while(tc--){
    bool check = false;
    queue<pair<int,int>> Q1 = {}, Q2 = {};
    cin >> w >> h;
    for(int i = 0; i < h; ++i){
      fill(fvis[i], fvis[i]+w, 0);
      fill(pvis[i], pvis[i]+w, 0);
    }
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; ++j){
        char c;
        cin >> c;
        if(c == '#') board[i][j] = -1;
        else{
          if(c == '@'){
            Q2.push({i,j});
            pvis[i][j] = 1;
          }
          else if(c == '*'){
            Q1.push({i,j});
            fvis[i][j] = 1;
          }
          board[i][j] = 0;
        }
      }
    while(!Q1.empty()){//불 bfs
    auto cur = Q1.front(); Q1.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx<0||nx>=h||ny<0||ny>=w) continue;
      if(board[nx][ny] == -1) continue;
      if(fvis[nx][ny])continue;
      fvis[nx][ny] = fvis[cur.X][cur.Y]+1;
      Q1.push({nx,ny});
      }
    }
    while(!Q2.empty() && (!check)){ //사람 bfs
      auto cur = Q2.front(); Q2.pop();
      for(int dir = 0; dir < 4; ++dir){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx<0||nx>=h||ny<0||ny>=w){
          cout << pvis[cur.X][cur.Y] << '\n';
          check = true;
          break;
        }
        if( board[nx][ny] == -1) continue;
        if(pvis[nx][ny]) continue;
        if(fvis[nx][ny] != 0 && fvis[nx][ny] <= pvis[cur.X][cur.Y]+1)continue;
        pvis[nx][ny] = pvis[cur.X][cur.Y]+1;
        Q2.push({nx, ny});
      }
    }
    if(!check){
      cout << "IMPOSSIBLE"<<'\n';
    }
  }
  return 0;
}
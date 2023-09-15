#include <bits/stdc++.h>

#define MAX 111
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int T, h, w, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
bool visited[MAX][MAX], key[29];
char board[MAX][MAX];
string s;
queue<pair<int,int>> Q, door[29];

void initVisit(){
  for(int i=0;i<h;++i) 
    for(int j=0;j<w;++j)
      visited[i][j]=0;
}

void initDoor(){
  for(int i=0;i<27;++i)
    while(!door[i].empty())
      door[i].pop();
}

void pushDoor(int i, int j){
  while(!door[board[i][j]-'a'].empty()){
    int x, y;
    tie(x, y) = door[board[i][j]-'a'].front();door[board[i][j]-'a'].pop();
    Q.push({x, y});
    board[x][y] = '.';
    visited[x][y] = 1;
  }
}

int bfs(){
  int cnt = 0;
  while(!Q.empty()){
    int x, y;
    tie(x,y) = Q.front();Q.pop();
    for(int dir=0;dir<4;++dir){
      int nx=x+dx[dir],ny=y+dy[dir];
      if(nx<0||h<=nx||ny<0||w<=ny)continue;
      if(visited[nx][ny] || board[nx][ny]=='*')continue;
      if(('A'<=board[nx][ny] && board[nx][ny] <= 'Z') && !key[board[nx][ny]-'A']){
        door[board[nx][ny]-'A'].push({nx,ny});
        continue;
      }
      else if(('a'<=board[nx][ny] && board[nx][ny] <= 'z') && !key[board[nx][ny]-'a']){
        key[board[nx][ny]-'a'] = 1;
        pushDoor(nx, ny);
      }
      else if(board[nx][ny] == '$') cnt++;
      board[nx][ny] = '.';
      visited[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  return cnt;
}

int main(){
  init();
  cin >> T;
  while(T--){
    int ans = 0;
    memset(key,0,sizeof(key));
    initDoor();
    initVisit();
    cin >> h >> w;
    for(int i=0;i<h;++i)
      for(int j=0;j<w;++j)
        cin>>board[i][j];
    cin >> s;
    for(int i:s) key[i-'a'] = 1;
    for(int i=0;i<h;++i){
      for(int j=0;j<w;++j){
        if((((i==0||i==h-1)&&(0<=j&&j<w))||((j==0||j==w-1)&&(0<=i&&i<h))) && board[i][j] != '*'){
          if(('A'<=board[i][j] && board[i][j] <= 'Z') && !key[board[i][j]-'A']){
            door[board[i][j]-'A'].push({i,j});
            continue;
          }
          else if(('a'<=board[i][j] && board[i][j] <= 'z') && !key[board[i][j]-'a']){
            key[board[i][j]-'a'] = 1;
            pushDoor(i, j);
          }
          else if(board[i][j] == '$') ans++;
          board[i][j] = '.';
          visited[i][j] = 1;
          Q.push({i, j});
          ans+=bfs();
        }
      }
    }
    cout << ans << '\n';
  }

  // for(int i = 0; i < h; ++i){
  //   for(int j = 0; j < w; ++j){
  //     cout << board[i][j];
  //   }
  //   cout << "\n";
  // }
  return 0;
}
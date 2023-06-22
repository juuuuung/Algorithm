#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int m, n, kmax;
bool arr[1001][1001];
bool v[1001][1001][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main()
{
  init();
  cin >> n >> m >> kmax;
  for(int i = 0; i < n; ++i){
    string str;
    cin >> str;
    for(int j =0; j < m; ++j){
      arr[i][j] = str[j]-'0';
    }
  }
  queue<tuple<int, int, int, int>> Q;
  Q.push({0,0,0,1});
  v[0][0][0] = 1;
  while(!Q.empty()){
    int x, y, wc, cnt;
    tie(x,y,wc,cnt) = Q.front();
    Q.pop();
    if(x == n-1 && y == m-1){
      cout << cnt;
      return 0;
    }
    for(int dir = 0; dir < 4; ++dir){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(v[nx][ny][wc]) continue;

      if(arr[nx][ny] == 1 && wc < kmax && v[nx][ny][wc+1] == 0){
        Q.push({nx, ny, wc+1, cnt+1});
        v[nx][ny][wc+1] = 1;
      }

      if(!arr[nx][ny]&&!v[nx][ny][wc]){
        Q.push({nx, ny, wc, cnt+1});
        v[nx][ny][wc] = 1;
      }
    }
  }
  cout << -1;
  return 0;
}
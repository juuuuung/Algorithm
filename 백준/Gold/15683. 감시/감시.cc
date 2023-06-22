#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n,m;
int board1[10][10];
int board2[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> cctv;

bool OOB(int x, int y){
  return (x < 0 || x >= n || y < 0 || y >= m);
}

void go(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x, y) || board2[x][y] == 6) return;
    if(board2[x][y] != 0) continue;
    board2[x][y] = 7;
  }
}

int main()
{
  init();
  int ans = 0;
  cin >> n >> m;
  for(int i =0; i < n; ++i){
    for(int j =0; j < m; ++j){
      cin >> board1[i][j];
      if(board1[i][j] != 6 && board1[i][j] != 0)
        cctv.push_back({i, j});
      ans += (board1[i][j] == 0);
    }
  }

  for(int temp = 0; temp<(1 << (2*cctv.size())); ++temp){
    //다름 배열에 원본 배열 복사
    for(int i =0; i < n; ++i)
      for(int j =0; j < m; ++j)
        board2[i][j] = board1[i][j];

    int brute = temp;
    for(int i =0; i < cctv.size(); ++i){
      int dir = brute%4;
      brute/=4;
      int x, y;
      tie(x, y) = cctv[i];
      if(board1[x][y] == 1){//1번 cctv라면 한방향
        go(x, y, dir);
      }
      else if(board1[x][y] == 2){
        go(x, y, dir);
        go(x, y, dir+2);
      }
      else if(board1[x][y] == 3){
        go(x, y, dir);
        go(x, y, dir+1);
      }
      else if(board1[x][y] == 4){
        go(x,y, dir);
        go(x, y, dir+1);
        go(x, y, dir+2);
      }
      else if(board1[x][y] == 5){
        go(x,y,dir);
        go(x, y, dir+1);
        go(x, y, dir+2);
        go(x, y, dir+3);
      }
    }
    int result = 0;
    for(int i =0; i < n; ++i)
      for(int j =0; j < m; ++j)
        result += (board2[i][j] == 0);
    ans = min(ans, result);
  }
  cout << ans;
  return 0;
}
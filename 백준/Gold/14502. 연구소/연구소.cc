#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m, result = 0;
int board1[9][9], board2[9][9];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<pair<int, int>>zero,virus;

bool OOB(int nx, int ny){
  return nx < 0 || nx >= n || ny < 0 || ny >= m;
}

void bfs(){
  queue<pair<int, int>> V;
  for(auto i : virus)V.push(i);
  while(!V.empty()){ //empty라고 하면 다음에는 바이러스 전파 불가능
    auto cur = V.front();V.pop(); 
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(OOB(nx, ny) || board2[nx][ny] != 0)continue;
      V.push({nx, ny});
      board2[nx][ny] = 2;
    }
  }
}

int main()
{
  init();
  cin >> n >> m;
  for(int i =0; i < n; ++i){
    for(int j =0; j < m; ++j){
      cin >> board1[i][j];
      if(board1[i][j] == 2)virus.push_back({i, j});
      else if(board1[i][j] == 0)zero.push_back({i, j});
    }
  }

  vector<bool> per(zero.size(), 1);
  per[0] = per[1] = per[2] = 0;

  do{
    //복사
    for(int i =0; i < n; ++i)
      for(int j =0; j < m; ++j)
        board2[i][j] = board1[i][j];

    //벽 3개 세우기(조합 사용)
    for(int i = 0; i < zero.size(); ++i)
      if(per[i] == 0)
        board2[zero[i].X][zero[i].Y] = 1;

    bfs();
    int ans = 0;
    for(int i =0; i < n; ++i)
      for(int j =0; j < m; ++j)
        ans += (board2[i][j] == 0);
    result = max(ans, result);
  }while(next_permutation(per.begin(), per.end()));
  cout << result;
  return 0;
}
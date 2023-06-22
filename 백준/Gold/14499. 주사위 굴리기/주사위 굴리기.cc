#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

//   [1]
//[5][2][6]
//   [3] 
//   [4]

int n, m, x, y, k;
int board[21][21];
int dice[7] = {};
int idx[5][4] = {
  {},
  {2,6,4,5},
  {2,5,4,6},
  {2,1,4,3},
  {2,3,4,1}
};

bool OOB(int nx, int ny){
  return nx < 0 || nx >= n || ny < 0 || ny >= m;
}

void roll(int cmd){
  int tmp[7];
  for(int i =1; i <= 6; ++i)tmp[i] = dice[i];
  for(int i =0; i < 4; ++i)
    tmp[idx[cmd][(i+1)%4]] = dice[idx[cmd][i]];
  for(int i =1; i <= 6; ++i)dice[i] = tmp[i];
}

int main()
{
  init();
  cin >> n >> m >> x >> y >> k;
  for(int i =0; i < n; ++i)
    for(int j =0; j < m; ++j)
      cin >> board[i][j];
  
  while(k--){
    int command, nx = x, ny = y;
    cin >> command;
    if(command == 1) ny++;
    else if(command == 2)ny--;
    else if(command == 3)nx--;
    else nx++;
    if(OOB(nx, ny))continue;
    x = nx;y = ny;
    roll(command);
    if(board[x][y] == 0)
      board[x][y] = dice[4];
    else{
      dice[4] = board[x][y];
      board[x][y] = 0;
    }
    cout << dice[2] << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, total = 0;
int board1[21][21],board2[21][21];

void rotate(){ //회전
  int tmp[21][21];
  for(int i =0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      tmp[i][j] = board2[i][j];
  
  for(int i =0; i < n; ++i)
    for(int j =0; j < n; ++j)
      board2[i][j] = tmp[n-1-j][i];
}

void swap(int dir){
  while(dir--) rotate();
  for(int h = 0; h < n; ++h){
    int tmp[21] = {0,}, cur = 0;
    bool merge[21] = {0,};
    for(int i =0; i < n; ++i){
      if(board2[h][i] == 0)continue;
      if(tmp[cur] == 0)tmp[cur] = board2[h][i];
      else if(tmp[cur] == board2[h][i]) tmp[cur++] *= 2;
      else tmp[++cur] = board2[h][i];
    }
    for(int i =0; i < n; ++i)board2[h][i] = tmp[i];
  }
}

int main()
{
  init();
  cin >> n;
  for(int i =0; i < n; ++i)
    for(int j =0; j < n; ++j)
      cin >> board1[i][j];

  for(int per = 0; per < (1<<10); ++per){
    for(int i =0; i < n; ++i)
      for(int j =0; j < n; ++j)
        board2[i][j] = board1[i][j];

    int brute = per;
    for(int i = 0; i < 5; ++i){
      int dir = brute%4;
      brute/=4;
      swap(dir);
    }
    int cnt = 0;
    for(int i =0; i < n; ++i)
      for(int j =0; j < n; ++j)
        total = max(total, board2[i][j]);
  }
  cout << total;
  return 0;
}
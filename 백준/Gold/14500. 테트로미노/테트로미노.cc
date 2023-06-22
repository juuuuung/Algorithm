#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m; // 보드의 행렬
int r, c; // 테트리스 모델의 행렬

int board1[501][501]; //원본 배열
int board2[100][100]; //복사 배열

int result = 0;

int model[7][5][5] = {
  {{1,4}, {1,1,1,1}},
  {{2,2}, {1,1},{1,1}},
  {{2,3}, {1,1,1},{0,1,0}},
  {{3,2}, {1,0},{1,0},{1,1}},
  {{3,2}, {1,0},{1,1},{0,1}},
  {{3,2}, {0,1},{0,1},{1,1}},
  {{3,2}, {0,1}, {1,1}, {1,0}}
};

void sum(int x, int y){
  int ans = 0;
  for(int i =0; i < r; ++i){
    for(int j =0; j < c; ++j){
      if(board2[i][j] == 1)
        ans += board1[x+i][y+j];
    }
  }
  result = max(ans, result);
}

void rotate(){ //모델 돌리기
  int tmp[5][5];
  for(int i =0; i < r; ++i)
    for(int j =0; j < c; ++j)
      tmp[i][j] = board2[i][j];
  for(int i =0; i < c; ++i)
    for(int j =0; j < r; ++j)
      board2[i][j] = tmp[r-1-j][i];
  swap(r, c);
}

int main()
{
  init();
  cin >> n >> m;
  for(int i=0; i< n; ++i)
    for(int j =0; j < m; ++j)
      cin >> board1[i][j];

  //모든 경우의 수 조사
  for(int k = 0; k < 7; ++k){
    r = model[k][0][0];
    c = model[k][0][1];

    //모델 복사
    for(int i =0; i < r; ++i)
      for(int j =0; j < c; ++j)
        board2[i][j] = model[k][i+1][j];
    
    // 밖을 넘어가지 못하도록
    for(int rot =0; rot < 4; ++rot){
      for(int x =0; x <= n-r; ++x){
        for(int y = 0; y <= m-c; ++y){
          sum(x, y);
        }
      }
      rotate();
    }
  }
  cout << result;
  return 0;
}
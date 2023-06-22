// 재귀 - 종이의 개수
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, board[2200][2200], ans[3];
bool f(int row, int col, int size){
  //비교할 시작점
  int start = board[row][col];
  for(int i = row; i < row + size; ++i){
    for(int j = col; j < col + size; ++j){
      if(start != board[i][j]) return false;
    }
  }
  return true;
}

void divide(int row, int col, int num){
  if(f(row, col, num)){
    ans[board[row][col]]++;
  }
  else{
    int size = num/3;
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        divide(row+size*i, col+size*j, size);
      }
    }
  }
}

int main()
{
  init();
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int input;
      cin >> input;
      ++input;
      board[i][j] = input;
    }
  }
  divide(0,0,n);
  cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
  return 0;
}
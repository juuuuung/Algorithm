#include <bits/stdc++.h>
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

bool board[64][64];
int n;

bool isRight(int row, int col, int size){
  int start = board[row][col];
  for(int i = row; i < row + size; ++i){
    for(int j = col; j < col + size; ++j){
      if(start != board[i][j])return false;
    }
  }
  return true;
}

void division(int row, int col, int size){
  if(isRight(row, col, size))cout << board[row][col];
  else{
    cout<<"(";
    int half = size/2;
    for(int i =0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
        division(row+half*i, col+half*j, half);
      }
    }
    cout << ")";
  }
}

int main(){
  init();
  cin >> n;
  string str;
  for(int i = 0; i < n; ++i){
    cin>>str;
    for(int j = 0; j < n; ++j){
      board[i][j] = str[j]-'0';
    }
  }
  division(0,0,n);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int board1[11][11];
vector<pair<int,int>> zeroList;
int zeroSize;
bool isPossible = false;

//find my near square
void dfs(int inx){
  if(zeroSize == inx){
    for(int i = 0; i < 9; ++i){
      for(int j = 0; j < 9; ++j){
        cout << board1[i][j];
      }
      cout << '\n';
    }
    isPossible = true;
    return;
  }

  bool noNum[11];
  memset(noNum, 0, sizeof(noNum));
  int x, y;
  tie(x, y) = zeroList[inx];
  
  //check my near square
  if(0<=x && x<=2){
    if(0<= y && y <= 2){
      for(int i=0; i<=2;++i)
        for(int j=0;j<=2;++j )
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(3 <= y && y <= 5){
      for(int i=0;i<=2;++i)
        for(int j=3;j<=5;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(6 <= y && y <= 8){
      for(int i = 0; i <= 2; ++i)
        for(int j=6; j<=8;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }
  }else if(3 <= x && x <= 5){
    if(0<= y && y <= 2){
      for(int i=3; i<=5;++i)
        for(int j=0;j<=2;++j )
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(3 <= y && y <= 5){
      for(int i=3;i<=5;++i)
        for(int j=3;j<=5;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(6 <= y && y <= 8){
      for(int i = 3; i <= 5; ++i)
        for(int j=6; j<=8;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }
  }else if(6 <= x && x <= 8){
    if(0<= y && y <= 2){
      for(int i=6; i<=8;++i)
        for(int j=0;j<=2;++j )
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(3 <= y && y <= 5){
      for(int i=6;i<=8;++i)
        for(int j=3;j<=5;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }else if(6 <= y && y <= 8){
      for(int i = 6; i <= 8; ++i)
        for(int j=6; j<=8;++j)
          if(board1[i][j]) noNum[board1[i][j]] = true;
    }
  }
  // check (가로)
  for(int j = 0; j < 9; ++j) if(board1[x][j]) noNum[board1[x][j]] = true;

  // check (세로)
  for(int i = 0; i < 9; ++i) if(board1[i][y]) noNum[board1[i][y]] = true;

  bool can = false;
  for(int i = 1; i <= 9; ++i) 
    if(!noNum[i]) can = true;

  if(!can) return;

  for(int i = 1; i <= 9; ++i){
    if(isPossible) return;
    if(!noNum[i]){
      board1[x][y] = i;
      dfs(inx+1);
      board1[x][y] = 0;
    }
  }
}

int main(){
  init();
  for(int i = 0; i < 9; ++i){
    for(int j = 0; j < 9; ++j){
      char t;
      cin >> t;
      board1[i][j] = t-'0';
      if(!board1[i][j])
        zeroList.push_back({i, j});
    }
  }

  if(zeroList.empty()){
    for(int i = 0; i < 9; ++i){
      for(int j = 0; j < 9; ++j){
        cout << board1[i][j] << ' ';
      }
      cout << '\n';
    }
  }else{
    zeroSize = zeroList.size();
    dfs(0);
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int MX = 1024 * 3;
char board[3073][MX*2+1];

void star(int s, int x, int y){
  if(s == 3){
    board[x][y] = '*';
    board[x+1][y-1] = '*';board[x+1][y+1] = '*';
    for(int i =y-2; i <= y+2; ++i){
      board[x+2][i] = '*'; 
    }
    return;
  }
  int ns = s/2;
  star(ns, x, y);
  star(ns, x+ns, y-ns);
  star(ns, x+ns, y+ns);
}

int main()
{
  init();
  int n;
  cin >> n;
  star(n, 0, n-1);
  for(int i =0; i < n;++i){
    for(int j =0; j < 2*n; ++j){
      if(board[i][j] == '*')cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}
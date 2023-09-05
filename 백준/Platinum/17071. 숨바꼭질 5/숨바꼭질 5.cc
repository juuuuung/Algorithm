#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, k, acceleration = 1;
bool board[2][500'002];
queue<int> Q;

int main(){
  init();
  cin >> n >> k;

  if(n == k){
    cout << 0;
    return 0;
  }

  Q.push(n);
  board[0][n] = true;
  while(!Q.empty()){
    k += acceleration;
    if(k > 500'000){
      cout << -1;
      return 0;
    }
    if(board[acceleration%2][k]){
      cout << acceleration;
      return 0;
    }
    int size = Q.size();
    for(int i= 0; i < size; ++i){
      int x = Q.front(); Q.pop();
      for(int dir : {x+1, x-1, x*2}){
        if(dir == k){
          cout << acceleration;
          return 0;
        }
        if(0 > dir || dir > 500'000)continue;
        if(board[acceleration%2][dir]) continue;
        Q.push(dir);
        board[acceleration%2][dir] = true;
      }
    }
    acceleration++;
  }
  cout << -1;
  return 0;
}


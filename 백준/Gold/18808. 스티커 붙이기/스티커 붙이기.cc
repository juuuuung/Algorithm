#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

bool sticker[11][11], note[42][42];

int n, m, tc, sr, sc;

void rotate(){
  int tmp[12][12];
  
  for(int i = 0; i < sr; i++)
    for(int j = 0; j < sc; j++)
      tmp[i][j] = sticker[i][j];
  
  for(int i = 0; i < sc; i++)
    for(int j = 0; j < sr; j++)
      sticker[i][j] = tmp[sr-1-j][i];
  swap(sr, sc);
}

bool func(int x, int y){
  for(int i =0; i < sr; ++i){
    for(int j =0; j < sc; ++j){
      if(note[x+i][y+j] == 1 && sticker[i][j] == 1)return false;
    }
  }

  for(int i =0; i < sr; ++i){
    for(int j =0; j < sc; ++j){
      if(sticker[i][j] == 1)
        note[x+i][y+j] = 1;
    }
  }
  return true;
}

int main()
{
  init();
  int ans = 0;
  cin >> n >> m >> tc;
  while(tc--){
    cin >> sr >> sc;
    for(int i =0; i < sr; ++i)
      for(int j =0; j < sc; ++j)
        cin >> sticker[i][j];

    bool isRight = false;
    for(int rot = 0; rot < 4; ++rot){
      for(int i =0; i <= n-sr; ++i){
        if(isRight)break;
        for(int j =0; j <= m-sc; ++j){
          if(func(i, j)){isRight = true;break;}
        }
      }
      if(isRight) break;
      rotate();
    }
  }
  for(int i=0; i < n; ++i)
    for(int j =0; j < m; ++j)
      ans += note[i][j]; 

  cout << ans;
  return 0;
}
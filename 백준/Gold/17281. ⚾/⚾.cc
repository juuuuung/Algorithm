#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int totalIning,games[51][10],order[9] = {1,2,3,4,5,6,7,8,9};
bool rue[4] = {0,0,0,0};
int outCnt = 0;
int point = 0, maxPoint = 0;

void start(int situation){
  if(situation == 0){
    ++outCnt;
  }else if(situation < 4){
    for(int i = 3; i > 0; --i){
      if(rue[i] == 1){
        if(i+situation < 4)rue[i+situation] = rue[i];
        else ++point;
        rue[i] = 0; 
      }
    }
    rue[situation] = 1;
  }
  else{
    int cnt = 0;
    for(int i = 1; i <= 3; ++i){
      if(rue[i]){
        rue[i] = 0;
        ++cnt;
      }
    }
    point+= (cnt+1);
  }
}

int main(){
  init();
  cin >> totalIning;
  for(int i = 1; i <= totalIning; ++i)
    for(int j = 1; j <= 9; ++j)
      cin >> games[i][j];

  do{
    int last = 0;
    swap(order[0], order[3]);
    for(int i = 1; i <= totalIning; ++i){
      int inx = last;
      while(outCnt < 3){
        start(games[i][order[inx%9]]);
        inx++;
      }
      outCnt = 0;
      last = inx;
      for(int j = 1; j <= 3; ++j)rue[j] = 0;
    }
    maxPoint = max(maxPoint, point);
    point = 0;
    swap(order[3], order[0]);
  } while(next_permutation(order+1, order+9));
  cout << maxPoint;
  return 0;
}
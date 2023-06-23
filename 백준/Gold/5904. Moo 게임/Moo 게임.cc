//Moo 게임
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
//횟수 
int n;
int tot = 3;
void moo(int x){
  if(x == 0){
    if(n == 1)cout <<"m";
    else cout << "o";
    return;
  }
  //가운데 컨텍스트의 시작 부분
  int half = (tot/2) - (x+3)/2+1;
  int endHalf = half + (x+2);

  // 찾는 글자가 외쪽 컨텍스트에 있을 때
  if(n < half){
    tot -= (tot-half)+1;
    moo(x-1);
  }
  // 찾는 글자가 가운데 컨텍스트라면
  else if(half <= n && n <= endHalf){
    if(n == half)cout << "m";
    else cout << "o";
  }
  //찾는 글자가 왼쪽 컨텍스트에 있다면
  else if (n > half){
    n -= endHalf;
    tot -= endHalf;
    moo(x-1);
  }
  return;
}

int main(){
  init();
    cin >> n;
    tot = 3;
    int cur = 1;
    while(1){
      if(tot < n){
        tot = tot * 2 + (cur+3);
        cur++;
        continue;
      }
      break;
    }
    moo(--cur);
  return 0;
}
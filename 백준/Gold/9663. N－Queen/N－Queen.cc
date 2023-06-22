#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, cnt = 0;
bool isused1[35];
bool isused2[35];
bool isused3[35];

void queen(int k){
  if(k == n){
    cnt++;
    return;
  }
  for(int i = 0; i < n; ++i){
    if(isused1[i] || isused2[k+i] || isused3[k-i+n-1])continue;
    isused1[i] = 1;
    isused2[k+i] = 1;
    isused3[k-i+n-1] = 1;
    queen(k + 1);
    isused1[i] = 0;
    isused2[k+i] = 0;
    isused3[k-i+n-1] = 0;
  }
    
}

int main()
{
  init();
  cin >> n;
  queen(0);
  cout << cnt;
  return 0;
}
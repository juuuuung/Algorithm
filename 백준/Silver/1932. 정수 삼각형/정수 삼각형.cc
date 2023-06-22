#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
int d[502][501];

int main(){
  init();
  cin >> n;
  for(int i =1; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      cin >> d[i][j];
    }
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      d[i][j] = d[i][j] + max(d[i-1][j], d[i-1][j-1]);

  cout << *max_element(d[n]+1, d[n]+n+1);
  return 0;
}
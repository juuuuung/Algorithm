#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, s, e;
int t;
int arr[2003];
bool dp[2002][2002];



int main(){
  init();
  cin >> n;
  for(int i = 1; i <= n; ++i){
    dp[i][i] = 1;
    cin >> arr[i];
  }

  for(int i = n; i > 0; --i){
    for(int j = i+1; j <= n; ++j){
      if(j == i+1 && arr[i] == arr[j]){
        dp[i][j] = 1;
        continue;
      }
      if(arr[i] == arr[j] && dp[i+1][j-1])
        dp[i][j] = 1;
      else
        dp[i][j] = 0;
    }
  }

  
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    cout << (dp[a][b] ? 1 : 0) << '\n';
  }

  return 0;
}
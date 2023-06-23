#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string A, B;
int dp[1003][1003];

int main(){
  init();
  cin >> A >> B;
  for(int i = 1; i <= A.length(); ++i){
    for(int j = 1; j <= B.length(); ++j){
      if(A[i-1] == B[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp[A.length()][B.length()];
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string A, B;
int dp[1002][1002];
int dx[2] = {0, -1};
int dy[2] = {-1, 0};

stack<char> str;

int main(){
  init();
  cin >> A >> B;
  for(int i = 1; i <= A.length(); ++i)
    for(int j = 1; j <= B.length(); ++j)
      dp[i][j] = (A[i-1]==B[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]));

  int x = A.length(), y = B.length();
  while(dp[x][y] != 0){
    if(dp[x + dx[0]][y + dy[0]] == dp[x][y]){
      x += dx[0]; 
      y += dy[0];
    }
    else if(dp[x + dx[1]][y + dy[1]] == dp[x][y]){
      x += dx[1]; 
      y += dy[1];
    }
    else{
      str.push(A[--x]);
      --y;
    }
  }
  cout << dp[A.length()][B.length()] <<'\n';
  while(!str.empty()){
    cout << str.top();
    str.pop();
  }
  return 0;
}
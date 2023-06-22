#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int board[301][301];
int main()
{
  init();
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j =0; j < m; ++j)
      cin >> board[i][j];

  int tc;
  cin >> tc;
  while(tc--){
    int X1,Y1,X2,Y2,sum = 0;
    cin >> X1 >> Y1 >> X2 >> Y2;
    for(int i =(X1-1); i < X2; ++i){
      for(int j = (Y1-1); j < Y2; ++j){
        sum += board[i][j];
      }
    }
    cout << sum << '\n';
  }
  return 0;
}
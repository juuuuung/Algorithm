#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main()
{
  init();
  int c, ans[51];
  cin >> c;
  for(int i =0; i < c; ++i)cin >> ans[i];
  sort(ans, ans+c);
  cout << ans[0] * ans[c-1];

  return 0;
}
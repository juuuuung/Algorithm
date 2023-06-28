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
  int tc,cnt =0;
  cin >> tc;
  while(tc--){
    string str;
    stack<char> S;
    cin >> str;
    for(char c : str){
      if(!S.empty() && S.top() == c)S.pop();
      else S.push(c);
    }
    if(S.empty())cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, m, cnt = 0;
string name;
vector<string> board;
int main(){
  init();
  unordered_map<string, int> M;
  cin >> n >> m;
  for(int i =1; i <= n; ++i){
    cin >> name;
    M.insert({name, i});
  }
  for(int i = 0; i < m; ++i){
    cin >> name; 
    if(M[name]!=0){
      board.push_back(name);
      cnt++;
    }
  }
  sort(board.begin(), board.end());
  cout << cnt << '\n';
  for(string i : board) cout << i << '\n';
  
  return 0;
}
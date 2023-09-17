#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, m;
unordered_map<string,int> M;
string board[100'002];
string name;

int main(){
  init();
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> name;
    board[i] = name;
    M.insert({name,i});
  }

  for(int i = 0; i < m; ++i){
    cin >> name;
    bool isNum = true;
    for(char i : name) if(!isdigit(i)) isNum = false; 
    if(!isNum) cout << M[name] << '\n';
    else  cout << board[stoi(name)] << '\n';
  }


  return 0;
}
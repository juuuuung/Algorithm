#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, m, cnt = 0;
bool knowList[52];
vector<int> board[51];

int main(){
  init();
  cin >> n >> m;
  int howMany, person;
  cin >> howMany;
  for(int i = 0; i < howMany;++i){
    cin >> person;
    knowList[person] = true;
  }

  for(int i = 0; i < m; ++i){
    cin >> howMany;
    for(int j = 0; j < howMany; ++j){
      cin >> person;
      board[i].push_back(person);
    }
  }
  for(int k = 0; k < m; ++k){
    for(int i = 0; i < m; ++i){
      for(int j : board[i]){
        if(knowList[j]){
          for(int o : board[i])
            knowList[o] = true;
          break;
        }
      }
    }
  }

  for(int i = 0; i < m; ++i){
    bool isLie = false;
    for(int j : board[i]){
      if(knowList[j]){
        isLie = true;
        break;
      }
    }
    if(!isLie)cnt++;
  }

  cout << cnt;
  return 0;
}

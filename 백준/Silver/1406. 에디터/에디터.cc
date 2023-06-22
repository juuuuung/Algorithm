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
  //변수들
  int n;
  string s;
  char command;
  list <char> alpha;

  //입력
  getline(cin, s);
  cin >> n;

  // 연결리스트 제작
  for(const char e : s)alpha.push_back(e);
  list<char>::iterator cursor = alpha.end();

  while(n > 0){
    --n;
    cin >> command;
    if(command == 'L' && cursor != alpha.begin()){
      --cursor;
    } else if(command == 'D' && cursor != alpha.end()){
      ++cursor;
    } else if(command == 'B' && cursor != alpha.begin()){
      cursor--;
      cursor = alpha.erase(cursor);
    } else if(command == 'P'){
      char add;
      cin >> add;
      alpha.insert(cursor, add);
    }
  }

  for(char &e : alpha) cout << e;
  return 0;
}
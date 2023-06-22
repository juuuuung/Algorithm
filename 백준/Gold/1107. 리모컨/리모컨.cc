#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
bool breakDown[11];

bool check(int num){
  string st = to_string(num);
  for(int i = 0; i < st.length(); ++i)
    if(breakDown[st[i]-'0']) return false;
  return true;
}

int main(){
  init();
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int num;
    cin >> num;
    breakDown[num] = true;
  }
  int minimum = abs(n-100);
  for(int i = 0; i <= 1'000'000; ++i){
    int tmp = 0;
    if(check(i)){
       tmp = abs(n-i)+to_string(i).length();
       minimum = min(minimum, tmp);
    }
  }
  cout << minimum <<'\n';
  return 0;
}
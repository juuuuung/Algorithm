#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
stack<int> s;

int main(){
  init();
  cin >> n;
  while(n--){
    int num; cin >> num;
    if(s.empty()){
      s.push(num);
      continue;
    }
    if(s.top() < num){
      while(!s.empty() && s.top() <= num){
        s.pop();
      }
      s.push(num);
    }else if(s.top() > num){
      s.push(num);
    }
  }
  cout << s.size();

  return 0;
}
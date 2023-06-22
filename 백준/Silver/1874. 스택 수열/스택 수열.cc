//스택 수열 스택으로 입력된 수열을 만들 수 있다
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
  int t;
  cin >> t;
  stack<int> s;
  string ans;
  int nxt_int = 1;
  vector<int> sequence(t);
  for(int i=0; i < t; ++i){cin >> sequence[i];}
  for(int e: sequence){
    if(s.empty()||s.top() < e){ //스택이 비어 있다면 nxt_int 부터 값(e)만큼 채우고 nxt_int 그만큼 증가 (반복문)
      for(int i=0, save_nxt = nxt_int; i <= e - save_nxt; ++i){
        s.push(nxt_int++);
        ans += "+\n";
      }
    } else if(s.top() != e){ // 위의 값이 같지 않다면 위의 조건을 모두 만족 하지 못한다면 NOPE!
      cout << "NO" << '\n';
      return 0;
    }
    s.pop();
    ans += "-\n";
  }
  cout << ans;

  return 0;
}
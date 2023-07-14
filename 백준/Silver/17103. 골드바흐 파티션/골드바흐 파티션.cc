// 골드바흐 파티션
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int Max = 1'000'000;
vector<bool> check(Max+1, 1);
int n;
void decimal(){
  for(int i = 2; i*i <= Max; ++i){
    if(!check[i])continue;
    for(int j = i*i; j <= Max; j += i) check[j] = 0;
  }
}
int main(){
  init();
  decimal();
  cin >> n;
  while(n--){
    int num, ans = 0;
    cin >> num;
    for(int i= 2; i <= num/2; ++i)
      if(check[i] && check[num-i]) ans++;
    cout << ans << '\n';
  }
  return 0;
}
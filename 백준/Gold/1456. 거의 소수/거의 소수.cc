#include <bits/stdc++.h>
typedef unsigned long long int uli;
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int Max = 10'000'000;
uli result = 0, a, b;
vector<bool> arr(Max+1, 1);
void decimal(){
  for(int i = 2; i * i<= Max; ++i){
    if(!arr[i]) continue;
    for(int j = i*i; j <= Max; j += i) arr[j] = 0;
  }
}
int main(){
  init();
  decimal();
  arr[0] = 0, arr[1] = 0;
  cin >> a >> b;
  for(uli i = 2; i <= Max; ++i){
    uli cnt = i;
    if(!arr[i])continue;
    while(cnt <= b/i){
      result += (cnt * i >= a);
      cnt *= i;
    }
  }
  cout << result;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
string str;
int num[100005], judge = 0, sizee;
bool zero = false;
int main(){
  init();
  cin >> str;
  sizee = str.size();
  for(int i = 0; i < sizee; ++i){
    judge += (str[i] -'0');
    num[i] = str[i]-'0';
    if(!zero && str[i]-'0' == 0) zero = true;
  }
  if(judge % 3 != 0 || !zero){
    cout << -1;
    return 0;
  } 
  sort(num, num+sizee, greater<>());
  str = "";
  for(int i= 0; i < sizee; ++i) str += (num[i] + '0');
  cout << str;
  return 0;
}
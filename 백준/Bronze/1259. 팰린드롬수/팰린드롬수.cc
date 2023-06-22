#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main(){
  init();
  while(1){
    string n;
    bool isFine = true;

    cin >> n;
    if(n=="0")break;

    int cur1 = 0, cur2 = n.size()-1;

    while(cur1 <= cur2){
      if(n[cur1] != n[cur2]){
        isFine = false;
        break;
      }
      else cur1++; cur2--;
    }
    cout << (isFine?"yes" : "no") << '\n';
  }
  return 0;
}
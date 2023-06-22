#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

void hanoi(int n, int start, int via, int end){
  if(n == 1){
    cout << start << ' ' << end << '\n';
  }
  else{
    hanoi(n-1, start, end, via);
    cout << start << ' ' << end << '\n';
    hanoi(n-1, via, start, end); 
  }
}

int main()
{
  init();
  int n;
  cin >> n;
  string a = to_string(pow(2,n));
  int x = a.find('.');
  a = a.substr(0,x);
  a[a.length() - 1] -= 1;
  cout << a << '\n';
  if(n <= 20){
    hanoi(n, 1, 2, 3);
  }
  return 0;
}
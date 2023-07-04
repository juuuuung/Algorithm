#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, arr[52];
int main(){
  init();
  cin >> n;
  for(int i= 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr+n);
  int i = 0;
  int ans = 0;
  while(arr[i] < 0){
    if(i+1 < n && arr[i+1] <= 0){
      ans += arr[i] * arr[i+1];
      i+=2;
      continue;
    }
    ans += arr[i];
    i++;
  }
  i = n-1;
  while(arr[i] > 0){
    if(i-1 >= 0 && arr[i-1] > 1){
      ans += (arr[i] * arr[i-1]);
      i-=2;
      continue;
    }
    ans += arr[i];
    i--;
  }
  cout << ans << ' ';

  return 0;
}
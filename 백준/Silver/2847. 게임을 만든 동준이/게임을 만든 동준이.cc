#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, arr[102];
int main(){
  init();
  cin >> n;
  for(int i= 1; i <= n; ++i)cin >> arr[i];
  int ans = 0;
  for(int i = n-1; i > 0; --i)
    if(arr[i] >= arr[i+1]){
      ans += arr[i]-arr[i+1]+1;
      arr[i] = arr[i]-(arr[i]-arr[i+1])-1;
    }
  cout << ans;
  return 0;
}
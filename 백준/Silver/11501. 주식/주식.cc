#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int tc, n;
int arr[1'000'005];
int main(){
  init();
  cin >> tc;
  while(tc--){
    cin >> n;
    for(int i = 0; i < n; ++i)
      cin >> arr[i];
    int Max = 0;
    long long ans = 0;
    for(int i = n-1; i > -1; --i){
      if(arr[i] > Max) Max = arr[i];
      else ans += (Max-arr[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
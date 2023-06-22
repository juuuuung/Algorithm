#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
int arr[1001], d[1001], pre[1001];

int main(){
  init();
  cin >> n;
  for(int i = 1; i <= n; ++i)cin >> arr[i];

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j < i; ++j){
      if(arr[i] > arr[j] && d[i] < d[j] + 1){
        d[i] = d[j] + 1;
        pre[i] = j;
      }
    }
  }

  int maxi = 1; int maxd = d[1];
  for(int i =1; i <= n; ++i){
    if(maxd < d[i]){
      maxi = i;
      maxd = d[i];
    }
  }

  deque<int> ans;
  int cur = maxi;
  while(cur){
    ans.push_front(arr[cur]);
    cur = pre[cur];
  }

  cout << ans.size() << '\n';
  for(auto x : ans)cout << x << ' ';
  
  return 0;
}
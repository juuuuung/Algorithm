#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int tc, n, m;
int arr[101] = {0,};

int main()
{
  init();
  cin >> tc;
  while(tc--){
    cin >> n >> m;
    queue<pair<int, bool>> Q;
    int cnt = 0;
    for(int i =0; i < n; ++i){
      int num;
      cin >> num;
      Q.push({num, (i == m)? 1 : 0});
      arr[i] = num;
    }

    sort(begin(arr), begin(arr)+n, greater<int>());

    for(int i =0; i < n; ++i){
      bool isOk = false;
      while(1){
        auto cur = Q.front();
        if(cur.first == arr[i] && cur.second == 1){
          cout << ++cnt << '\n';
          isOk = true;
          break;
        }
        else if(cur.first != arr[i]){
          Q.push(Q.front());
          Q.pop();
        }
        else if(cur.first == arr[i] && cur.second == 0){
          Q.pop();
          cnt++;
          break;
        }
      }
      if(isOk)break;
    }
  }
  return 0;
}
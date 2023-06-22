#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int pre[5001], nxt[5001], len, N, K;
vector <int> v;


int main()
{
  init();
  cin >> N >> K;
  for(int i = 1; i <= N; ++i){
    pre[i] = (i == 1) ? N : i-1;
    nxt[i] = (i == N) ? 1 : i+1;
    ++len;
  }
  // k번째 확인 하기 K = 3;
  int i = 1;
  for(int cur = 1; len > 0; cur = nxt[cur]){
    if(i == K){
      pre[nxt[cur]] = pre[cur];
      nxt[pre[cur]] = nxt[cur];
      v.push_back(cur);
      --len;
      i = 1;
    } else ++i;
  }
  cout << "<";
  for(int i = 0; i < v.size(); ++i){
    cout << v[i];
    if(i != v.size()-1) cout << ", "; 
  }
  cout << ">";
  
  return 0;
}
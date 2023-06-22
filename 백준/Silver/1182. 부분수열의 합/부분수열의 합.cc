// 백트래킹 - 부분 수열의 합
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int tc, s, cnt = 0;
int nums[21];

void part(int sum, int nxt){
  if(nxt == tc){
    if(sum == s)++cnt;
    return;
  }
  part(sum, nxt+1);
  part(sum+nums[nxt], nxt+1);
}

int main()
{
  init();
  cin >> tc >> s;
  for(int i =0; i < tc; ++i)cin >> nums[i];
  part(0, 0);
  if(s == 0) --cnt;
  cout << cnt;
  return 0;
}
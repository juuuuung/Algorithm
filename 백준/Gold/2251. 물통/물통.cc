// 포도주 시식
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int A, B, C;
bool bottle[201][201][201];

queue <tuple<int, int, int>> q;
vector<int> result;

int main(){
  init();
  cin >> A >> B >> C;
  q.push({0, 0, C});
  while(!q.empty()){
    int a, b, c;
    tie(a, b, c) = q.front(); q.pop();
    
    if(bottle[a][b][c])continue;
    bottle[a][b][c] = true;
    
    if(a == 0) result.push_back(c);

    //c -> a
    if(a + c > A)q.push({A, b, c-(A-a)});
    else q.push({a + c, b, 0});
    //c -> b
    if(c + b > B)q.push({a, B, c-(B-b)});
    else q.push({a, b+c, 0});

    //b -> c
    if(b + c > C) q.push({a, b-(C-c), C});
    else q.push({a, 0, b+c});
    //b -> a
    if(a + b > A) q.push({A, b-(A-a), c});
    else q.push({a+b, 0, c});
    
    //a -> b
    if(a + b > B) q.push({a-(B-b), B, c});
    else q.push({0, a+b, c});
    //a -> c
    if(a + c > C)q.push({a-(C-c), b, C});
    else q.push({0, b, a+c});
  }

  sort(result.begin(), result.end());
  for(int i : result)cout << i << ' ';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
string arr[51];

bool cmp(const string a,const string b){
  if(a.size() < b.size()) return true;
  else if(a.size() > b.size()) return false;
  else{//같을 때
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < a.size(); ++i){
      if(isdigit(a[i]) != 0)
        ans1 += (a[i]-'0');
      if(isdigit(b[i]) != 0)
        ans2 += (b[i] - '0');
    }
    if( ans1 < ans2) return true;
    else if (ans1 > ans2)return false;
    else{ //크기도 같다면
      for(int i =0; i < a.size(); ++i){
        if(a[i] < b[i])return true;
        else if(a[i] == b[i])continue;
        else return false;
      }
    }
  }
  return false;
}

int main()
{
  init();
  cin >> n;
  for(int i =0; i < n; ++i)cin >> arr[i];
  sort(arr, arr+n, cmp);
  for(int i =0; i < n; ++i) cout << arr[i] << '\n';
  return 0;
}
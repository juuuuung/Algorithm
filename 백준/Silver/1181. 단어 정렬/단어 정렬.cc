#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n;
string str;

bool cmp(string &a, string &b){
  int lena = a.size(), lenb = b.size();
  if(lena != lenb) return lena < lenb;
  return a < b;
}

int main()
{
  init();
  cin >> n;
  vector<string> v(n);
  for(int i =0; i < n; ++i){
    cin >> str;
    v[i] = str;
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  for(string &s: v)cout << s <<'\n';
  return 0;
}
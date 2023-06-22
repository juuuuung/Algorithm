#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m;
int arr[100'001], in[100'001];
int focus = 0;

bool binSearch(int st, int en){
  if(st >= en){
    return (arr[st] == focus?true : false);
  }
  int mid = (st + en)/2;
  if(arr[mid] < focus) return binSearch(mid+1, en);
  else if(arr[mid] == focus) return true;
  else return binSearch(st, mid-1);
}

int main(){
  init();
  cin >> n;
  for(int i =0; i < n; ++i)cin >> arr[i];
  sort(arr, arr+n);
  cin >> m;
  for(int i = 0; i < m; ++i)cin >> in[i];

  for(int i = 0; i < m; ++i){
    focus = in[i];
    cout << binSearch(0, n-1) << '\n';
  }
  return 0;
}
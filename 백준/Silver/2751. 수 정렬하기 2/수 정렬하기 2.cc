#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int arr[1'000'000], tmp[1'000'000];
void merge(int st, int en){
  int mid = (st+en)/2;
  int cur1 = st, cur2 = mid;
  for(int i = 0; i < (en-st); ++i){
    if(cur1 == mid)tmp[i] = arr[cur2++];
    else if(cur2 == en)tmp[i] = arr[cur1++];
    else if(arr[cur1] <= arr[cur2])tmp[i] = arr[cur1++];
    else tmp[i] = arr[cur2++];
  }
  for(int i =0; i < (en-st); ++i)arr[st+i] = tmp[i];
}

void merge_sort(int st, int en){
  if(st+1 != en) {
    int mid = (st + en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
  }
}

int main()
{
  init();
  int n;
  cin >> n;
  for(int i =0; i < n; ++i)cin >> arr[i];
  merge_sort(0, n);
  for(int i = 0; i < n; ++i)cout << arr[i] << '\n';
  return 0;
}
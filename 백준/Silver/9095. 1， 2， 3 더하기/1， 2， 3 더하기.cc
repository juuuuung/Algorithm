#include <bits/stdc++.h>

using namespace std;

int T, input, arr[20]={0,};

int main(void){
  cin >> T;
  arr[1] = 1, arr[2] = 2, arr[3] = 4;
  for(int i = 4; i <= 11; ++i) arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  while(T--){
    cin >> input;
    cout << arr[input] << '\n';
  }
  return 0;
}
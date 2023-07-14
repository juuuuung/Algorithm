#include <bits/stdc++.h>

typedef unsigned long long int uli;
using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int Max = 10'000'000;
uli a, b, result = 0;

vector<int> decimal(){
  vector<bool> arr(Max+1, 1);
  vector<int> primes;
  for(uli i = 2; i*i <= Max; ++i){
    if(!arr[i]) continue;
    for(uli j = i*i; j <= Max; j += i)
      arr[j] = 0;
  }
  for(int i = 2; i <= Max; ++i)
    if(arr[i])primes.push_back(i);
  return primes;
}

int main(){
  init();
  cin >> a >> b;
  vector<int> primes = decimal();
  for(int p : primes)
    for(uli i = p; i <= b/p; i*=p)
      result += (i*p>= a);
  cout << result;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

char letter[16], ans[16];
int C[15], l, c;

bool OOB(char x){
  return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int main()
{
  init();
  cin >> l >> c;

  for(int i =0; i < c; ++i)cin >> letter[i];
  sort(letter, letter+c);
  
  for(int i = l; i < c; ++i)C[i] = 1;

  do{
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0; i < c; ++i){
      if(!C[i]){
        if(OOB(letter[i]))cnt1++;
        else cnt2++;
      }
    }
    if(cnt1 > 0 && cnt2 > 1){
      for(int i = 0; i < c; ++i)if(!C[i])cout << letter[i];
      cout << '\n';
    }
  }while(next_permutation(C, C+c));
  return 0;
}
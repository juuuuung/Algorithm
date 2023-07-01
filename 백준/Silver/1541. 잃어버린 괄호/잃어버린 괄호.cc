#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string str;

char oper[30];
int arr[30];

int main(){
  init();
  cin >> str;
  string num="";
  int ocur = 0, acur = 0;
  for(int i= 0; i < str.size(); ++i){
    if(str[i] == '+' || str[i]== '-'){
      oper[ocur++] = str[i];
      arr[acur++] = stoi(num);
      num = "";
    }
    else num+=str[i];
  }
  arr[acur++] = stoi(num);
  int cur = 0, size = acur, ans = arr[0];
  while(cur < size){
    int tmp = 0;
    if(oper[cur] == '+') tmp+=arr[++cur];
    // '-' 라면
    else{
      while(cur < size && oper[++cur] == '+'){
        tmp+=arr[cur];
      }
      tmp+=arr[cur];
      tmp = -tmp;
    }
    ans += tmp;
  }
  cout << ans;

  
  return 0;
}
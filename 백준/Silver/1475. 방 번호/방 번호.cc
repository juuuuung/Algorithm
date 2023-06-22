#include <bits/stdc++.h>

using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    init();
    vector <int> result(9);
    string s;
    getline(cin, s);
    for(char &a: s){
        int num = a-'0';
        if(num == 6 || num == 9)result[6]++;
        else result[num]++;
    }
    result[6] = ceil(result[6]/2.0);
    cout << *max_element(result.begin(), result.end()) << '\n';

    return 0;
}
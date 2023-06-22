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
    int T;
    cin >> T;
    while (T > 0){
        --T;
        int a, b;
        cin >> a >> b;
        b = b % 4 == 0 ? 4 : b % 4;
        int p = pow(a, b);
        if(p%10 == 0){
            cout << 10 << "\n";
        }
        else {
            cout << p%10 << "\n";
        }
    }
    return 0;
}
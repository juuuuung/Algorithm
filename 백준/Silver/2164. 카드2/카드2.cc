#include <bits/stdc++.h>

using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
queue<int> Q;
int main()
{
    init();
    int n;
    cin >> n;
    for(int i =1; i < n+1; ++i) Q.push(i);
    while(Q.size() != 1){
        Q.pop();
        int front = Q.front();
        Q.pop();
        Q.push(front);
    }
    cout << Q.front() << '\n';
    return 0;
}
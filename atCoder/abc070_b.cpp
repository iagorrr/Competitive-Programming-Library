// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

vector<int> hold(101, 0);
int main()
{
    int a, b; cin >> a >> b;
    for(int i = a; i < b; ++i) hold[i]++;

    cin >> a >> b;
    for(int i = a; i < b; ++i) hold[i]++;
    
    int ans = 0;
    for(int i = 0; i < 101; ++i) ans += hold[i] > 1 ? 1 : 0;

    cout << ans << '\n';
}

// AC.

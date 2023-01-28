// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

int main(){ 
    fastio
    short unsigned int r, g ,b;
    cin >> r >> g >> b;

    cout << ((g*10 + b) % 4 == 0 ? "YES" : "NO") << '\n';;
    return 0;
}

// AC.

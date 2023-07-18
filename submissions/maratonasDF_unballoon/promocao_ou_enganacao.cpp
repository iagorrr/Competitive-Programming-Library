#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, r, m, p; cin >> n >> r >> m >> p;

    ll mmc = lcm(n, m);
    ll pa = mmc / n * r;
    ll pb = mmc / m * p;

    if(pb < pa) cout << "Promocao\n";
    else cout << "Enganacao\n";

    return 0;
}

// AC, math, lcm

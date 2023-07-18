#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, r, n;

    cin >> a >> b >> r >> n;

    ll R = (b / n) * (r + 1) + min(b%n, r);
    a--;
    ll L = (a / n) * (r + 1) + min(a%n, r);
    cout << R - max(0LL, L) << endl;

    return 0;
}

// AC, math, mod

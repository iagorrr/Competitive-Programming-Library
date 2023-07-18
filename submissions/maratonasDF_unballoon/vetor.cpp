#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, c, k; cin >> n >> c >> k;

    ll ans = 0;
    while (c < n) {
        c *= k;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}

// AC, math

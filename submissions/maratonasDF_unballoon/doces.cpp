// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
        ll n, m;
        cin >> n >> m;
        ll best = -1;
        while (n--) {
                ll x;
                cin >> x;
                if (best == -1) best = x;
                if (x % m < best % m) best = x;
                if (x % m == best % m and x > best) best = x;
        }
        cout << best << '\n';
}

// AC, math

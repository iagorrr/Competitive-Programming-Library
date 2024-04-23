#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
        ll n, k;
        cin >> n >> k;

        if (n == 1) {
                cout << k << '\n';
                return;
        }
        
        // maximizar o número de 1's no or
        // decompoem o maximo que der os bits do K ??
        //
        // tenta somar as potencias até da K
        // o ultimo sobra
        //

        set <int> sps;
        while (k) {
                ll p2 = 1;

                while (p2*2 <= k) {
                        if (!sps.count(p2)) break;
                        p2 *= 2;
                }

                if (sps.count(p2)) break;
                sps.emplace(p2);

                k -= p2;
        }

        vector<ll> ans(n);
        int m = n - (k != 0);
        int i = 0;
        while (!sps.empty()) {
                ans[i % m] += *sps.rbegin();
                i++;
                sps.erase(*sps.rbegin());
        }
        if (k) ans.back() = k;

        for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i==n-1];
        }
}

int main()  {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;

        while (t--)
                run();
}
 

// AC, constructive, math, bitmasks

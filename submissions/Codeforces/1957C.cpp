#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1'000'000'000 + 7;
const int maxn = 3'00'000;

ll memo[maxn + 1];

ll solve(int m) {
        if (m <= 1) return 1;

        auto &ans = memo[m];
        if (ans != -1) return ans;

        auto c1  = solve(m-1);
        auto c2 = ((2 * (m-1+mod) ) % mod) * solve(m-2);

        return ans = (c1 + c2) % mod;
}

auto run() {
        int n, k;
        cin >> n >> k;

        vector<char> ar(n+1), ac(n+1);
        int m = n;
        for (int i = 0, r, c; i < k; i++) {
                cin >> r >> c;
                m--;
                if (r != c) m--;
        }
        
        cout << solve(m) << '\n';
}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        memset(memo, -1, sizeof memo);

        int t;
        cin >> t;

        while (t--) {
                run();
        }
}

// AC, combinatorics, dp, math

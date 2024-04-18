#include <bits/stdc++.h>
using namespace std;

using ld = long double;

auto run() {
        int N, M, K;        
        cin >> N >> M >> K;

        vector<char> KS(N*3);
        for (int i = 0, ki; i < K; i++) {
                cin >> ki;
                KS[ki] = true;
        }


        bool invalid = false;
        for (int i = 0, cs = 0; i <= N; i++) {
                cs = KS[i] ? cs + 1 : 0;
                if (cs >= M) invalid = true;

        }

        if (invalid) {
                cout << - 1 << '\n';
                return;
        }

        vector<ld> ev(N+M+1);
        vector<ld> f0(N+M+1);

        ld mev=0, f0m=0;
        ld frac = (ld)1 / (ld)M;
        for (int i = N-1; i >= 0; i--) {
                mev += ev[i+1], mev -= ev[i+M+1];
                f0m += f0[i+1], f0m -= f0[i+M+1];

                if (KS[i]) {
                        f0[i] = (ld)1.0000000;
                }
                else {
                        f0[i] = (ld)f0m * frac;
                        ev[i] = (ld)mev * frac + (ld)1.0000;
                }
        }

        ld denom = (ld)1.0 - f0[0];
        ld ans = ev[0] / denom;

        cout << fixed << setprecision(10) << ans << '\n';

}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        run();
}

// AC, expected value, math

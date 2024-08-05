#include <bits/stdc++.h>
using namespace std;

#include "../../../../../algorithms/graphs/Heavy-Light Decomposition (point update)/Maximum Number on Path.cpp"

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define _fastio                       \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

int T = 1;
#define eb emplace_back

auto run() {
        int N, Q;
        cin >> N >> Q;

        vector<Node> VS(N);
        _rep(i, 0, N) {
                int vi;
                cin >> vi;
                VS[i] = Node(vi);
        }

        vi2d ADJ(N);
        _rep(i, 0, N - 1) {
                int a, b;
                cin >> a >> b;
                a--, b--;

                ADJ[a].eb(b);
                ADJ[b].eb(a);
        }

        HeavyLightDecomposition hld(ADJ, VS);

        _rep(q, 0, Q) {
                int o;
                cin >> o;

                if (o & 1) {
                        int s, x;
                        cin >> s >> x;
                        s--;
                        hld.set(s, Node(x));
                } else {
                        int a, b;
                        cin >> a >> b;
                        a--, b--;
                        auto res = hld.query_path(a, b);
                        cout << res.value << ' ';
                }
        }

        cout << endl;
}

int32_t main() {
#ifndef LOCAL
        _fastio;
#endif

        // cin >> T;

        _rep(t, 0, T) {
                dbg(t);
                run();
        }
}

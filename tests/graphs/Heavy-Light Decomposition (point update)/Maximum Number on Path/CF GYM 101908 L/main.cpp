#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b)                                     \
        for (common_type_t<decltype(a), decltype(b)> i = \
                 a;                                      \
             i != b; (a < b) ? ++i : --i)
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define rep(i, a, b)                                     \
        for (common_type_t<decltype(a), decltype(b)> i = \
                 a;                                      \
             i != b; (a < b) ? ++i : --i)
#define sz(x) (int)x.size()

using ll = long long;
using vi = vector<int>;
using vi2d = vector<vi>;
int T = 1;

#include "../../../../../algorithms/graphs/Heavy-Light Decomposition (point update)/Maximum Number on Path.cpp"

int merged(vector<pii> a, vector<pii> b) {
	dbg(a);
	dbg(b);
	int ret = 0;
	vector<pii> c= a;
	for (auto bi  : b)
		c.pb(bi);

	sort(all(c), [](pii x, pii y) {
			return x.first == y.first ? x.second > y.second : x.first < y.first;
	});

	auto [l, r] = c.front();
	rep(i, 1, sz(c)) {
		auto [l2, r2] = c[i];
		if (l2 > r) {
			l = l2;
			r = r2;
		}
		else {
			int il = max(l, l2);
			int ir = min(r2, r);
			ret = ret + ir - il + 1;
			r = max(r2, r);
		}
	}

	dbg(ret);
	return ret;
}
auto run() {
        int N, Q;
        cin >> N >> Q;

        vi2d ADJ(N);
        rep(i, 0, N - 1) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                ADJ[u].eb(v);
                ADJ[v].eb(u);
        }

	vector<Node> tmp(N);
        HeavyLightDecomposition hld(ADJ, tmp);

        rep(q, 0, Q) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                a--, b--, c--, d--;

		int ans =  0;
		ans += merged(hld.disjoint_ranges(a, b), hld.disjoint_ranges(c, d));

		cout << ans << endl;
        }
}

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        // cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

/*
        dar ++ no path de u -> lca(u,v) v -> lca(v, u)
        anpalogopro outro par de nós

        e dai só contar quantas posição é 2

        faz com hld e seg de historgrama

        dai bla bla bla fazer primeiro
 */

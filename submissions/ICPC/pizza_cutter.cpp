// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
#define all(x) x.begin(), x.end()
using pll = pair<ll,ll>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
	ll n, m;
	cin >> n >> m;
	ll h, v;
	cin >> h >> v;

	vector<pair<ll, ll>> hori(h), vert(v);
	for (auto &[x, y] : hori) cin >> x >> y;
	for (auto &[x, y] : vert) cin >> x >> y;

	sort(all(hori), [](pair<ll, ll> a, pair<ll, ll> b){
			return a.second > b.second;
	});
	sort(all(vert), [](pair<ll, ll> a, pair<ll, ll> b){
			return a.second > b.second;
	});

	ordered_set<ll> hori_x, vert_x;
	ll total_hori = 0;
	for (ll i = 0; i < h; i++)
	{
		auto total = hori_x.order_of_key(hori[i].first);
		total_hori += total;
		hori_x.insert(hori[i].first);
	}
	ll total_vert = 0;
	for (ll i = 0; i < v; i++)
	{
		auto total = vert_x.order_of_key(vert[i].first);
		total_vert += total;
		vert_x.insert(vert[i].first);
	}

	auto ans = (h+1)*(v+1) + total_hori + total_vert;
	cout << ans << '\n';
}

int32_t main() {
	fastio;
	solve();
}

// AC, ordered set, geometry.

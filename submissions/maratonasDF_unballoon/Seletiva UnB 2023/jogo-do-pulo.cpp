// iagorrr ;)
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)


void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }


map<ll, ll> factorization(ll n)
{
        map<ll, ll> ans;
        for (ll i = 2; i*i <= n; i++)
        {
                ll count = 0;
                for (; n%i==0; count++, n/=i);
                if (count)
                        ans[i] = count;
        }
        if (n > 1) ans[n]++;
        return ans;
}

ll phi(ll n)
{
        if (n == 1)
                return 1;

        auto fs = factorization(n);
        auto res = n;

        for (auto [p, k] : fs){
                res /= p;
                res *= (p - 1);
        }

    return res;
}

ll fexp(ll a, ll n, ll mod){
        if(n == 0) return 1;
        if (n==1) return a;
        ll x = fexp(a, n/2, mod);
        return x*x*(n&1?a:1) % mod;
}

void run() {
        ll n; cin >> n;

        ll p  = 2;
        while(gcd(n, p) != 1) p++;

        ll phii = phi(n)-1;
        ll ans =  fexp(p, phii, n);

        cout << ans << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, number theory

// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

const ll MAXN = 1e7+2;
vll list_primes(ll n) { // Nlog * log N
  vll ps;
  bitset<MAXN> sieve;
  sieve.set();
  sieve.reset(1);
  for (ll i = 2; i <= n; ++i) {
    if (sieve[i])
      ps.push_back(i);
    for (ll j = i * 2; j <= n; j += i) {
      sieve.reset(j);
    }
  }
  return ps;
}

vll all_primes;
map<ll, ll> factorial_fatoration(ll n) {
        map<ll, ll> ans;
        for(auto &p : all_primes) {
                ll pi = p;
                if(pi > n) break;
                while(pi <= n) {
                        ans[p] += n/pi;
                        pi *= p; 
                }
        } 
        return ans;
}

map<ll, ll> prime_factors(ll n) {
        map<ll,ll>ans;
        for(auto p : all_primes) {
                ll cnt = 0;
                while(n%p == 0) {
                        n /= p;
                        cnt++;
                }
		if(cnt)
			ans[p] = cnt;
        } 
	if(n != 1)  ans[n] = 1;
	return ans;        
}
void run() {
        all_primes = list_primes(MAXN-1);
        ll n, m; cin >> n >> m;

        auto mfact = factorial_fatoration(m);
        auto nfact = prime_factors(n);

	ll ans = LLONG_MAX;
	for(auto [pi, qi] : nfact) {
		// cout << "pi: " << pi << " qi: " << qi << '\n';
		ans = min(ans, mfact[pi]/qi);
	}

	cout << ans << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, prime factors

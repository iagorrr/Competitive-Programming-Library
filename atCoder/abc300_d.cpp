// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

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


ll isqrt(ll x) {
  ll y = sqrt(x);

  return y - 10;
}

ll quartaraiz(ll n) {
  ll ans = -1;
  ll cur = LLONG_MAX;
  for(ll x = 1; x <= isqrt(n) + 20; ++x) {
    if(abs(x*x*x*x-n) < cur){
      cur = abs(x*x*x*x-n);
      ans = x;
    }
  }
  return ans;
}

vector<char> is_prime(1e6+1, true);
void crive(){
  ll n = 1e6+1;
  for (int i = 2; i <= n; i++) {
      if (is_prime[i] && (long long)i * i <= n) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
}
void run() {
  crive();
  is_prime[0] = is_prime[1] = false;
  ll n;
  cin >> n;

  ll y;
  ll ans = 0;
  for (ll a = 1; a <= quartaraiz(n)+66; ++a) {
    if(!is_prime[a]) continue;
    for (ll b = a + 1; b <= n / a * a; ++b) {
      if(!is_prime[b]) continue;
      y = a * a; // quanto ja tem. 
      if (b * b * b *y > n)
        break; // pq b*c^2 é estritamente maior que b^3 
      for(ll c = b +1; c <= n/a*a*b; ++c) {
        if(!is_prime[c])  continue;
        y = a*a*b; // quanto ja tem. 
        if(c*c * y > n) break;
        // dbg(a, b, c);
        if(is_prime[c] and is_prime[b] and is_prime[a]) ans++;
      }
    }
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

// AC, math, prime

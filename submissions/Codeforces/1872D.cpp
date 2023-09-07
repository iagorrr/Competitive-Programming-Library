#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

ll nfirst(ll x) { return (x * (x + 1ll)) / 2ll; }

ll f(ll s, ll d, ll n) { return (s + (s + d * (n - 1))) * n / 2ll; }
void run() {
  ll n, x, y;
  cin >> n >> x >> y;

  // soma os de x, e diminuir os de y.

  // ok né
  if (x == y) {
    cout << 0 << endl;
    return;
  }

  // fudeu toda posição de x vai ser cancelada por y.
  if (y < x and x % y == 0) {
    // posicoes queo y vai ter so pra ele.
    ll py = n / y - n / x;

    // dou os menorzinhos pra ele kk.
    cout << -(py * (py + 1ll)) / 2ll << endl;
    return;
  }

  // nada em comum da os maiores pro x e os menores pro y.
  if (lcm(x, y) > n) {
    ll py = n / y;
    ll ty = nfirst(py);

    ll px = n / x;
    ll tx = nfirst(n) - nfirst(n - px);
    cout << tx - ty << endl;
    return;
  }

  // altas paradas em comum tem que ver essa bomba.

  // cancelo o minimo possivel de x.
  ll px = n / x;
  ll pxy = n / lcm(x, y);
  ll start = n - px + pxy + 1;
  ll howmuch = px - pxy;
  // cout << "start " << start << " howmuch " << howmuch << endl;
  ll tx = f(start, 1, howmuch);

  // dou o resto pro y.
  ll py = n / y;
  ll ty = nfirst(py - pxy);

  // cout << "tx: " << tx << " ty: " << ty << ' ';
  cout << tx - ty << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, math

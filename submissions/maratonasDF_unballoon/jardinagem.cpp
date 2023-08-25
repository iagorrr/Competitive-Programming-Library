// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 666
#endif
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using ld = long double;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
    for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
    for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

const ll INF = 1e18;

// two pointers
// ponteiro nas arestas
// cada aresta vira um vetor
// ver os dois arestas se o produto vetorial for negativo
// colocar o mínimo possível a cima do semiplano do vetor

const ld EPS = 1e-6;

typedef ld T;
bool eq(T a, T b) { return abs(a - b) <= EPS; }
struct point {
    T x, y;
    int id;
    point(T x = 0, T y = 0) : x(x), y(y) {}
    point operator+(const point &o) const { return {x + o.x, y + o.y}; }
    point operator-(const point &o) const { return {x - o.x, y - o.y}; }
    point operator*(T t) const { return {x * t, y * t}; }
    point operator/(T t) const { return {x / t, y / t}; }
    T operator*(const point &o) const {
        return x * o.x + y * o.y;
    }  // dot product
    T operator^(const point &o) const {
        return x * o.y - y * o.x;
    }  // cross product
};

ld dist(point a, point b) {
    point d = a - b;
    return sqrt(d * d);
}

void run() {
    int n;
    cin >> n;
    vector<point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // duplica pra caso queira 'dar a volta'
    int n2 = len(pts);
    for (int i = 0; i < n2; i++) {
        pts.eb(pts[i]);
    }

    // pega os vetores
    vector<point> vpts(len(pts));
    for (int i = 0; i < len(vpts) - 1; i++) {
        vpts[i].x = pts[i].x - pts[i + 1].x;
        vpts[i].y = pts[i].y - pts[i + 1].y;
    }

    // pega o tamanho de cada vetor
    vector<ld> sz(len(pts));
    for (int i = 0; i < len(pts) - 1; i++) {
        sz[i] = dist(pts[i], pts[i + 1]);
    }

    // camera infinitamente distante que consegue ver i
    ld ans = 0;
    ld cur = 0;
    for (int i = 0, j = 0; i < n; i++) {
        // adiciona cada aresta adjaceste enquanto o vetor não apontar pra dentro do polígno
        while (j < len(vpts) and (i == j or (vpts[i] ^ vpts[j]) > 0)) {
            cur += sz[j];
            j++;
        }
        ans = max(ans, cur);
        cur -= sz[i];
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    // cin >> t;
    while (t--) run();
}

// AC, geometry

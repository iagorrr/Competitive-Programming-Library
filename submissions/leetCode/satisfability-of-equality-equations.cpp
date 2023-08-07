// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                            \
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
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
        for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x)                                                  \
        for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), \
                cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
        cerr << ' ' << h;
        dbg_out(t...);
}
#define dbg(...)                             \
        {                                    \
                cerr << #__VA_ARGS__ << ':'; \
                dbg_out(__VA_ARGS__);        \
        }
const ll INF = 1e18;

struct DSU {
        vector<int> ps;
        vector<int> size;
        DSU(int N) : ps(N + 1), size(N + 1, 1) {
                iota(ps.begin(), ps.end(), 0);
        }
        int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
        bool same_set(int x, int y) { return find_set(x) == find_set(y); }
        void union_set(int x, int y) {
                if (same_set(x, y)) return;

                int px = find_set(x);
                int py = find_set(y);

                if (size[px] < size[py]) swap(px, py);

                ps[py] = px;
                size[px] += size[py];
        }
};
class Solution {
       public:
        bool equationsPossible(vector<string> &equations) {
                sort(all(equations), [](const string &a, const string &b) {
                        return a[1] > b[1];
                });
                DSU dsu('z' - 'a' + 1);
                for (auto &equation : equations) {
                        char a, b;
                        a = equation.front() - 'a';
                        b = equation.back() - 'a';
                        if (equation[1] == '!') {
                                if (dsu.same_set(a, b)) return false;
                        } else {
                                dsu.union_set(a, b);
                        }
                }
                return true;
        }
};

// AC, graphs, DSU, connected components

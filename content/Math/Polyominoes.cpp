/*8<
  @Title: Polyominoes
  @Usage:
    $buildPolyominoes(x)$ creates every polyomino
    until size x, and put it in $polyominoes[x]$,
    access $polyomino.v$ to find the vector of
    pairs representing the coordinates of each
    piece, considering that the polyomino was
    'rooted' in coordinate $(0,0)$.

  @Warning:
    note that when acessing $polyominoes[x]$ only
    the first $x$ coordinates are valid.
>8*/
const int MAXP = 10;

using pii = pair<int, int>;
// This implementation considers the rotations as
// distinct
//               0, 10, 10+9, 10+9+8...
int pos[11] = {0, 10, 19, 27, 34, 40, 45, 49, 52, 54, 55};
struct Polyominoes {
    pii v[MAXP];
    ll id;
    int n;
    Polyominoes() {
        n = 1;
        v[0] = {0, 0};
        normalize();
    }
    pii &operator[](int i) { return v[i]; }
    bool add(int a, int b) {
        for (int i = 0; i < n; i++)
            if (v[i].first == a and v[i].second == b) return false;
        v[n++] = pii(a, b);
        normalize();
        return true;
    }
    void normalize() {
        int mnx = 100, mny = 100;
        for (int i = 0; i < n; i++)
            mnx = min(mnx, v[i].first), mny = min(mny, v[i].second);
        id = 0;
        for (int i = 0; i < n; i++) {
            v[i].first -= mnx, v[i].second -= mny;
            id |= (1LL << (pos[v[i].first] + v[i].second));
        }
    }
};
vector<Polyominoes> polyominoes[MAXP + 1];
void buildPolyominoes(int mxN = 10) {
    vector<pair<int, int>> dt({{1, 0}, {-1, 0}, {0, -1}, {0, 1}});
    for (int i = 0; i <= mxN; i++) polyominoes[i].clear();
    Polyominoes init;
    queue<Polyominoes> q;
    unordered_set<int64_t> used;
    q.push(init);
    used.insert(init.id);
    while (!q.empty()) {
        Polyominoes u = q.front();
        q.pop();
        polyominoes[u.n].push_back(u);
        if (u.n == mxN) continue;
        for (int i = 0; i < u.n; i++) {
            for (auto [dx, dy] : dt) {
                Polyominoes to = u;
                bool ok = to.add(to[i].first + dx, to[i].second + dy);
                if (ok and !used.count(to.id)) {
                    q.push(to);
                    used.insert(to.id);
                }
            }
        }
    }
}

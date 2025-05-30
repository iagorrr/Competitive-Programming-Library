/*8<
  @Title:

    Functional/Successor Graph

  @Description:

    Given a functional graph find the vertice
    after $k$ moves starting at $u$ and also the
    distance between $u$ and $v$, if it's
    impossible to reach $v$ starting at $u$
    returns -1.

  @Time:

    build $O(N \cdot MAXLOG2)$, kth $O(MAXLOG2)$,
dist $O(MAXLOG2)$ >8*/

const int MAXN(2 '000' 000), MAXLOG2(24);
int N;
vi2d succ(MAXN, vi(MAXLOG2 + 1));
vi dst(MAXN, 0);

int vis[MAXN];
void dfsbuild(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    int v = succ[u][0];
    dfsbuild(v);
    dst[u] = dst[v] + 1;
}

void build() {
    for (int i = 0; i < N; i++) {
        if (not vis[i]) dfsbuild(i);
    }

    for (int k = 1; k <= MAXLOG2; k++) {
        for (int i = 0; i < N; i++) {
            succ[i][k] = succ[succ[i][k - 1]][k - 1];
        }
    }
}

int kth(int u, ll k) {
    if (k <= 0) return u;
    for (int i = 0; i <= MAXLOG2; i++)
        if ((1ll << i) & k) u = succ[u][i];
    return u;
}

int dist(int u, int v) {
    int cu = kth(u, dst[u]);
    if (kth(u, dst[u] - dst[v]) == v)
        return dst[u] - dst[v];
    else if (kth(cu, dst[cu] - dst[v]) == v)
        return dst[u] + (dst[cu] - dst[v]);
    else
        return -1;
}

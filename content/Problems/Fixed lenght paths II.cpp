#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2'00'000;

int N, K1, K2;
vector<int> ADJ[MAXN];

int64_t ans = 0;

int sz[MAXN], removed[MAXN];
void calcSize(int u, int p = -1) {
    sz[u] = 1;
    for (int v : ADJ[u]) {
        if (v != p and !removed[v]) {
            calcSize(v, u);
            sz[u] += sz[v];
        }
    }
}

int findCentroid(int u, int mxSz, int p = -1) {
    for (int v : ADJ[u]) {
        if (!removed[v] and v != p and sz[v] * 2 >= mxSz)
            return findCentroid(v, mxSz, u);
    }
    return u;
}

int64_t cnt[MAXN], totCnt[MAXN], initialSum;
int mxD;
void dfs(int u, int p, int d) {
    if (d > K2) return;
    cnt[d]++;
    mxD = max(mxD, d);
    if (K1 - 1 <= d and d <= K2 - 1) initialSum++;
    for (int v : ADJ[u]) {
        if (v != p and !removed[v]) {
            dfs(v, u, d + 1);
        }
    }
}

void solve(int curRoot) {
    calcSize(curRoot);
    int centroid = findCentroid(curRoot, sz[curRoot]);

    removed[centroid] = true;

    int totMxD = 0;
    initialSum = (K1 == 1);
    // cerr << "centroid: " << centroid << '\n';
    for (int v : ADJ[centroid]) {
        if (!removed[v]) {
            // cerr << "v: " << v << '\n';
            mxD = 0;
            int64_t curSum = initialSum;
            dfs(v, centroid, 1);
            totMxD = max(totMxD, mxD);

            for (int d = 1; d <= mxD; d++) {
                // cerr << "d : " << d << " curSum: " << curSum << '\n';
                ans += (curSum * cnt[d]);

                int pl = max(0, K1 - d) - 1;
                if (pl >= 0) curSum += totCnt[pl];
                int pr = K2 - d;
                curSum -= totCnt[pr];
            }

            for (int d = 1; d <= mxD; d++) totCnt[d] += cnt[d];

            fill(&cnt[1], &cnt[1] + mxD + 1, 0);
        }
    }

    // cerr << "centroid: " << centroid
    //<< " ans: " << ans << '\n';
    for (int d = 1; d <= totMxD; d++) totCnt[d] = 0;

    for (int v : ADJ[centroid])
        if (!removed[v]) solve(v);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    totCnt[0] = 1;
    cin >> N >> K1 >> K2;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ADJ[u].emplace_back(v);
        ADJ[v].emplace_back(u);
    }

    solve(0);

    cout << ans << '\n';
}

// AC, centroid decomposition

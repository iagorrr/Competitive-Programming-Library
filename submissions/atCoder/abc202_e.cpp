#include <bits/stdc++.h>
using namespace std;
template <class T>

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
struct MergeSortTree {
  int n;
  vector<vector<T>> st;
  MergeSortTree(vector<T> &xs) : n(len(xs)), st(n << 1) {
    for (int i = 0; i < n; i++)
      st[i + n] = vector<T>({xs[i]});

    for (int i = n - 1; i > 0; i--) {
      st[i].resize(len(st[i << 1]) + len(st[i << 1 | 1]));
      merge(all(st[i << 1]), all(st[i << 1 | 1]),
            st[i].begin());
    }
  }
  int count(int i, T a, T b) {
    return upper_bound(all(st[i]), b) -
           lower_bound(all(st[i]), a);
  }
  int inrange(int l, int r, T a, T b) {
    int ans = 0;

    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += count(l++, a, b);
      if (r & 1) ans += count(--r, a, b);
    }

    return ans;
  }
};


const int maxn = 2'00'000;
int n;
vector<int> adj[maxn];

vector<int> heights;
vector<int> prim, last;
vector<int> order;
vector<int> hs;

void dfs(int u, int h = 0) {
	prim[u] = order.size();
	hs[u] = h;
	order.push_back(u);
	heights.push_back(h);

	for (auto v : adj[u]) {
		dfs(v, h+1);
	}

	last[u] = (int)order.size() - 1;
}
void dbg() {
	cerr << "order: ";
	for (auto o : order)
		cerr << o << ' ';
	cerr << '\n';

	cerr << "heights: ";
	for (auto o : heights)
		cerr << o << ' ';
	cerr << '\n';


}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;

		adj[p].push_back(i);
	}
	
	prim.resize(n);
	last.resize(n);
	hs.resize(n);
	dfs(0, 0);

	MergeSortTree <int> mst(heights);
	int q;
	cin >> q;
	//dbg();

	while(q--) {
		int ui, di;
		cin >> ui >> di;
		ui--;

		int fd = di;
		int l = prim[ui], r = last[ui];
		//cerr << "ui: " << ui << " l: " << l  << " r : " << r << " fd: " << fd << '\n';
		int ans= mst.inrange(l, r, fd, fd);
		cout << ans << '\n';
	}
}

// AC, dfs, tree flatten, merge sort tree, data structures


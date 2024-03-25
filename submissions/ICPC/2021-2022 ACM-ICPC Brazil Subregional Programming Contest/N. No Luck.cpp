#include <bits/stdc++.h>
using namespace std;

template <class T>
struct MergeSortTree {
  int n;
  vector<vector<T>> st;
  MergeSortTree(vector<T> &xs) : n(xs.size()), st(n << 1) {
    for (int i = 0; i < n; i++)
      st[i + n] = vector<T>({xs[i]});

    for (int i = n - 1; i > 0; i--) {
      st[i].resize(st[i << 1].size() + st[i << 1 | 1].size());
      merge(st[i << 1].begin(), st[i<<1].end(),
	   st[i << 1 | 1].begin(), st[i << 1 | 1].end(),
            st[i].begin());
    }
  }
  int count(int i, T a, T b) {
    return upper_bound(st[i].begin(), st[i].end(), b) -
           lower_bound(st[i].begin(), st[i].end(), a);
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int y, n;
	cin >> y >> n;
	vector<int> ys(y);
	for (auto &yi : ys) cin >> yi;

	MergeSortTree mst(ys);

	while (n--) {
		int ai, pi, fi;
		cin >> ai >> pi >> fi;
		int l = ai-1, r = ai+fi-1;
		int ans = ys[l] >= pi ? 0 : mst.inrange(l, r, pi, 1'00'000);
		cout << ans << '\n';

	}
}

// AC, data-structures, merge sort tree

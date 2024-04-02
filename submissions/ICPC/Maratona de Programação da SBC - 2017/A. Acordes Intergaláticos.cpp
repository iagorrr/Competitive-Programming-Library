#include <bits/stdc++.h>
using namespace std;

#define a10 array<int,9>
//using a10 = array<int, 9>;

using q_node = a10; 
using l_node = int;

a10 e = {0,0,0,0,0,0,0,0,0};
a10 e2 = {0,1,0,0,0,0,0,0,0};

struct LazySegTree {
	int n, lg;
	vector<q_node> st;
       	vector<l_node> lazy;

	/*
	   how to combine two query nodes
	 */
	q_node combine(q_node a, q_node b) {
		auto ret = a;
		for (int i = 0; i < 9; i++) {
			ret[i] += b[i];

		}
		return ret;
	}

	/*
	   how to apply the lazy _x_ to the node
	   at position  _p_
	 */
	void apply(int p, l_node x, int sz, bool prop=1) {
		a10 tmp = e;

		for (int i = 0; i < 9; i++) {
			tmp[(i+x)%9] += st[p][i];

		}

		st[p] = tmp;

		if (prop and p < n) {
			lazy[p] += x;
		}
	}

	LazySegTree (int _n) : n(_n), lg(ceil(log2(n))), st(n<<1, e), lazy(n<<1) {
	}

	/* 	OPTIONAL
	   you can just build empty and
	   make n updates
	 */
	LazySegTree (const vector<q_node> &v) : n((int)v.size()), lg(ceil(log2(n))), st(n<<1,e), lazy(n<<1)  { 
		for (int i = 0; i < n; i++) st[n+i] = v[i];
		for (int i = n-1; i; i--) st[i] = combine(st[i<<1], st[i<<1|1]);
		for (int i = 0; i < n<<1; i++) lazy[i] = l_node();
	}


	void prop(int p) {
		int sz = 1 << (lg-1);
		for (int s = lg; s; s--, sz >>= 1) {
			int i = p >> s;
			if (lazy[i] != l_node()) {
				apply(i<<1, lazy[i], sz);
				apply(i<<1|1, lazy[i], sz);
				lazy[i] = l_node();
			}
		}
	}


	void fixup(int p) {
		for (int sz = 2; p >>= 1; sz <<= 1) {
			st[p] = combine(st[p<<1], st[p<<1|1]);
			apply(p, lazy[p], sz, 0);
		}
	}

	q_node query(int a, int b) {
		q_node ret = e;
		for (prop(a+=n), prop(b+=n); a <= b; ++a>>=1, --b>>=1) {
			if (a&1) ret = combine(ret, st[a]);
			if (!(b&1)) ret = combine(ret, st[b]);
		}
		return ret;
	}

	void update(int l, int r, l_node x) {
		int lo = l += n, ro = r += n, sz = 1;
		for (; l <= r; ++l>>=1, --r>>=1, sz <<= 1) {
			if (l&1) apply(l, x, sz);
			if (!(r&1)) apply(r, x, sz);
		}
		fixup(lo), fixup(ro);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<a10> aux(n, e2);

	LazySegTree st(aux);

	while (q--) {
		int l, r;
		cin >> l >> r;
		auto ret = st.query(l , r);
		int b = 0;
		for (int i = 0; i < 9; i++)
			if (ret[i] >= ret[b]) b = i;

		st.update(l, r, b);
	}


	for (int i = 0; i < n; i++) {
		auto ret = st.query(i, i);
		int b = 0;
		for (int j = 0; j < 9; j++)
			if (ret[j] >= ret[b]) b = j;

		cout << b << '\n';
	}
}

// AC, range query/update

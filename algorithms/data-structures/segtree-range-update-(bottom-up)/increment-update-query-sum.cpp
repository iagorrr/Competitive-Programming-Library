using q_node = long long;
using l_node = long long;
using u_node = long long;

struct LazySegTree {
	int n, lg;
	vector<q_node> st;
       	vector<l_node> lazy;

	LazySegTree (int _n) : n(_n), lg(ceil(log2(n))), st(n<<1), lazy(n<<1) {
	}

	/* 	OPTIONAL
	   you can just build empty and
	   make n updates
	 */
	LazySegTree (const vector<q_node> &v) : n((int)v.size()), lg(ceil(log2(n))), st(n<<1), lazy(n<<1)  { 
		for (int i = 0; i < n; i++) st[n+i] = v[i];
		for (int i = n-1; i; i--) st[i] = combine(st[i<<1], st[i<<1|1]);
		for (int i = 0; i < n<<1; i++) lazy[i] = l_node();
	}

	/*
	   how to combine two query nodes
	 */
	q_node combine(q_node a, q_node b) {
		return a+b;
	}

	/*
	   how to apply the lazy _x_ to the node
	   at position  _p_
	 */
	void apply(int p, l_node x, int sz, bool prop=1) {
		st[p] += x*sz;
		if (prop and p < n) lazy[p] += x;
	}

	void prop(int p) {
		int sz = 1 << (lg-1);
		for (int s = lg; s; s--, sz >>= 1) {
			int i = p >> s;
			if (lazy[i]) {
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
		q_node ret = 0;
		for (prop(a+=n), prop(b+=n); a <= b; ++a>>=1, --b>>=1) {
			if (a&1) ret = combine(ret, st[a]);
			if (!(b&1)) ret = combine(ret, st[b]);
		}
		return ret;
	}

	void update(int l, int r, u_node x) {
		int lo = l += n, ro = r += n, sz = 1;
		for (; l <= r; ++l>>=1, (--r)>>=1, sz <<= 1) {
			if (l&1) apply(l, x, sz);
			if (!(r&1)) apply(r, x, sz);
		}
		fixup(lo), fixup(ro);
	}
};

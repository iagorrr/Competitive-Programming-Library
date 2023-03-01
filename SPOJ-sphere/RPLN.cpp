#include <bits/stdc++.h>
using namespace std;

class SegTree{// bottom up.
	public:
		int N;
		vector<ll> st;

		SegTree(vector<ll> v) : N((int)v.size()), st((int)v.size()*4, LLONG_MAX)
		{
			for(int i = 0; i < N; ++i)
				update(1, 0, N-1, i, v[i], v);
		}

		void update(int node, int L, int R, int p, ll u, const vll &v)
		{
			if(L > p or p > R) return;

			if(L == R){
				st[node] = v[L];
				return;
			}

			int mid = L + (R-L)/2;
			
			update(node*2, L,  mid, p, u, v); update(node*2+1, mid+1, R, p, u, v);
			st[node] = min(st[node*2], st[node*2+1]);
		}

		ll MRQ(int l, int r)
		{
			return MRQ(1, 0, N-1, l, r);
		}
	private:
		ll MRQ(int node, int l, int r, int L, int R)
		{
			if(L <= l and R >= r) return st[node];
			if(l > R or r < L) return LLONG_MAX;
			if(l == r) return st[node];

			int mid = l + (r-l)/2;
			return min(MRQ(node*2, l, mid, L, R), MRQ(node*2+1, mid+1, r, L, R));
		}

				
};
// AC.

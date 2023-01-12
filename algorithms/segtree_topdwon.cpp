/*
 * iagorrr ;)
 * segtree top dowm implementation to vectors with any size.
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree
{
	public:
		int N;
		vector<T> st;
		
		// constructor, used 4N as a secure size and update it all.
		SegmentTree (vector<T> v): N((int)v.size()), st(4*(int)v.size(), 0)
		{
			for(int i = 0; i < N; ++i)
				update(i, v[i]);
		}

		// update recursive.
		void update(int p, T u)
		{
			update(1, 0, N-1, p, u); // root, L, R, index original, and value update.
		}

		// rsq recursive.
		void RSQ(int l, int r)
		{
			RSQ(1, 0, N-1, l, r); // root, L and R that it represents l and r that is the query.
		}
	private:
		void update(int node, int L, int R, int p, T u)
		{
			if(i > R or i < L) return; // this interval isn't affected by the p position.
			
			// update the segtree value.
			st[node] += u;

			// already in a leaf, finish here.
			if(L >= R) return;

			// go update childs until the leaf, left half and right half.
			int mid = L + (R-L)/2;	
			update(node*2, L, mid, p, u);
			update(node*2+1, mid+1, R, p, u);
		}
		
		T RSQ(int node , int L, int R, int l, int r)
		{
			if( (r < L) or (l > R) ) return 0; // there is no intersection ignore this node.

			if( (L >= l) and (R <= r) return st[node]; // the query contains the interval of the node return it all, every son is included.

			// check the childs that are contained by the query.
			int mid = L + (R-L)/2;
			T ls = RSQ(node*2, L, mid, l, r);
			T rs = RSQ(node*2+1, mid+1, R, l, r);

			return ls + rs; // sum of left and right childs.
		}








		


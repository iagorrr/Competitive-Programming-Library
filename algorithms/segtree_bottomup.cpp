/*
 * iagorrr ;)
 * segment tree implementation to vectors with size 2^
 * */
#include <bits/stdc++.h>
using namespace std;


template<typename T> // to use whatever you want.
class SegmentTree
{
    public:
        int N;
        vector<T> st;
        
        // contrucutor, takes the vector that will receive the queires.
        SegmentTree(const vector<T> &v) : N((int)v.size()), st((int)v.size()*2, 0)
        {
            // the last N elements will be the initial vector itself.
            copy(v.begin(), v.end(), st.begin()+N); // takes the source and the initial point of the target.

            // fill the sums based in their left and right child.
            for(int i = N-1; i >= 1; --i) // don't use the 0 index.
                st[i] = st[i*2] + st[i*2+1];
        }

        // RSQ, total sum in the interval r, l.
        T RSQ(int l, int r)
        {

            l += N; r += N; // the according position in the segtree.
            T s = 0;

            while(l <= r)
            {
                if(l&1) // unprocessed by parents process the value and increment.
                    s += st[l++];
                if(!(r&1)) // same thing but decrease.
                    s += st[r--];
                l /= 2; r /= 2; // considere the parents now.
            }

            return s;
        }

        // update a value in the original vector so change the sums influenced by it.
        void update(int p, int u)
        {
            p += N;
            st[p] += u;
            while(p <<= 1)
                st[p] += u;
        }
            
};


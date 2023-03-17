/*
 * iagorrr ;)
 * Segment tree implementation.
 *  sum operation
 *  top-down
 *  recursive
 *  range update
 *  lazy propagation
 *
 * */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree
{
    public:
        int N;
        vector<T> st;
        vector<T> lazy;

        // default initialization.
        SegmentTree(const vector<T> &v): N((int)v.size()), st((int)v.size()*4, 0), lazy((int)v.size()*4, 0)
        {
            for(int i = 0; i < N; ++i)
                update(i, i, v[i]); // l == r, meaning a single position.
        }

        // intervface for the update.
        void update(int l, int r, T u)
        {
            update(1, 0, N-1, l, r, u);
        }

        // interface to the RSQ.
        T RSQ(int l, int r)
        {
            return RSQ(1, 0, N-1, l, r);
        }
    private:
        // range update with lazy propagation.
        void update(int node, int L, int R, int l, int r, T u)
        {
            if(lazy[node]) 
            {
                // update the node knowing that the whole interval that it represents will me decremented.
                st[node] += (R-L+1) * lazy[node];
                
                if(L < R) // do the same to the child if isn't a leaf.
                {
                    lazy[2*node] += lazy[node];
                    lazy[2*node+1] += lazy[node];
                }

                lazy[node] = 0;
            }

            // after it update the childs as before.
            if( (R < l) || (L > r) ) return; // there is no intersection.

            // is contained update only the father and add the lazy to it childs.
            if( (L >= l) && (R <= r) )
            {
                // update the node considering that the whole range it represents will be updated.
                st[node] += (R-L+1) * u;

                if(L < R)
                {
                    lazy[node*2] += u;
                    lazy[node*2+1] += u;
                }

                return;
            }
    
            // update it childs considering that the current node isnt contained.
            int mid = L + (R-L)/2;
            update(node*2, L, mid, l, r, u);
            update(node*2+1, mid+1, R, l, r, u);

            // with the childs updated update the parent itself.
            st[node] = st[node*2] + st[node*2+1];

        }

        // RSQ now considering the lazy propagation
        T RSQ(int node, int L, int R, int l, int r){
            if(lazy[node]) 
            {
                // update the node itself.
                st[node] += (R-L+1) * lazy[node];

                // spread if isn't a leaf.
                if(L < R)
                {
                    lazy[node*2] += lazy[node];
                    lazy[node*2+1] += lazy[node];
                }
                
                lazy[node] = 0;
            }
            
            if( (L > r) or (R < l) ) return 0; // this interval isn't affect by the query

            if( (L >= l) and (R <= r) ) return st[node]; // the whole interval is accomplished.

            // take the childs that are included.
            int mid = L + (R-L)/2;
            T sl = RSQ(node*2, L, mid, l, r);
            T sr = RSQ(node*2+1, mid+1, R, l, r);

            return sl + sr;
        }
};

int32_t main(){
    return 0;
}

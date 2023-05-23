// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// segtree, point update, RMQ.
class SegTree{
    public:
        int n;
        vector<ll> st;
        SegTree(const vector<ll> &v): n((int)v.size()), st(n*4+1, LLONG_MAX){
            for(int i = 0; i < n; ++i)
                update(i, v[i]);
        }
        void update(int p, ll v){
            update(1, 0, n-1, p, v);
        }
        ll RMQ(int l, int r){
            return RMQ(1, 0, n-1, l, r);
        }
    private:
        void update(int node, int l, int r, int p, ll v){
            if(p < l or p > r) return; // fora do intervalo.
            
            if ( l == r ) {
                st[node] = v;
                return; 
            }
            
            int mid = l + (r-l)/2;

            update(node*2, l, mid, p, v); update(node*2+1, mid+1, r, p, v);
            
            st[node] = min(st[node*2], st[node*2+1]);
        }
        
        ll RMQ(int node, int L, int R, int l, int r){
            if(l <= L and r >= R) return st[node]; 
            if(L > r or R < l) return LLONG_MAX;    
            if(L == R) return st[node];

            int mid = L +(R-L)/2;

            return min(RMQ(node*2, L, mid, l, r), RMQ(node*2+1, mid+1, R, l, r));
        }
};


int32_t main()
{
    vector<ll> a{9, -1, 2, 11, 15, 0, 10, -3};
    SegTree s(a);

    while(true){
        cout << "original vector: "; for(auto x : a) cout << x << ' '; cout << '\n';
        cout << "segtree : "; for(auto x : s.st) cout << (x == LLONG_MAX ? "X" : to_string(x)) << ' '; cout <<'\n';

        cout << "1 to consult 0 to update: ";
        int op; cin >> op;
        
        if(op){
            cout << "Enter l and r: ";
            int l, r;
            cin >> l >> r;
            cout << "RMQ(" << l << ',' << r << "): " << s.RMQ(l, r) << '\n';
        }
        else{
            cout << "Enter position and value: ";
            ll v, p;
            cin >> p >> v;
            a[p] = v;
            s.update(p, v);
        }
    }
}

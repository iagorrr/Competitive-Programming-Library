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

                        update(node*2, l, mid, p, v);
                        update(node*2+1, mid+1, r, p, v);
                        
                        st[node] = min(st[node*2], st[node*2+1]);
                }
                
                ll RMQ(int node, int L, int R, int l, int r){
                        if(l <= L and r >= R) return st[node]; 
                        if(L > r or R < l) return LLONG_MAX;    
                        if(L == R) return st[node];

                        int mid = L +(R-L)/2;

                        return min(RMQ(node*2, L, mid, l, r),
                                   RMQ(node*2+1, mid+1, R, l, r));
                }
        };

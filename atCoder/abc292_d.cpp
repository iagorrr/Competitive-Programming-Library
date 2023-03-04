// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

class DSU{
    private:
        vector<int> ps;
        vector<int> size;
        vector<int> edg;
        int n;
    public:
        DSU(int N) : ps(N+1), size(N+1, 1), edg(N+1, 0), n(N){
            iota(ps.begin(), ps.end(), 0);
        }
        int find_set(int x){
            return ps[x] == x ? x : ps[x] = find_set(ps[x]);
        }
        bool same_set(int x, int y){
            return find_set(x) == find_set(y);
        }
        void increase_edg(int x) {
          edg[find_set(x)]++;
        }
        bool check(){
          for(int i = 1; i <= n; ++i){
            if(edg[find_set(i)] != size[find_set(i)]) return false;
          }
          return true;
        } 
        void union_set(int x, int y){
            if(same_set(x, y))
                return;

            int px = find_set(x);
            int py = find_set(y);

            if(size[px] < size[py]) swap(px, py);

            ps[py] = px;
            size[px] += size[py];
        }
};   


int32_t main(void){ fastio;
  int n, m; cin >> n >> m;
  DSU dsu(n);
  vector<pii> e;
  while(m--){
    int u, v; cin >> u >> v;
    e.emplace_back(u, v);
    dsu.union_set(u, v);
  } 

  for(auto [u, v] : e)
    dsu.increase_edg(u);

  cout << (dsu.check() ? "Yes" : "No") << '\n';

}

// AC, dsu, connect component.

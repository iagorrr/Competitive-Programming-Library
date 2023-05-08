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
        int n;
        vector<int> ps;
        vector<int> size;
    public:
        DSU(int N) : n(N), ps(N+1), size(N+1, 1){
            iota(ps.begin(), ps.end(), 0);
        }
        int find_set(int x){
            return ps[x] == x ? x : ps[x] = find_set(ps[x]);
        }
        bool same_set(int x, int y){
            return find_set(x) == find_set(y);
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
        int not_cycle(set<int> c) {
          int ans = 0;
          set<int> noc;
          for(int i = 1; i <= n; ++i) {
            if(not c.count(find_set(i)) and not noc.count(find_set(i))){ 
              ans++;
              noc.insert(find_set(i));
            }
          }
          return ans;
        }
};   

void run(){
  int n, m; cin >> n >> m;

  DSU dsu(n);
  int c = 0;
  set<int> u;
  for(int i = 0; i < m; ++i) {
    int a, b;
    char ac, bc;
    cin >> a >> ac >> b >> bc;
    
    if(dsu.same_set(a, b)){
      c++;
      u.insert(dsu.find_set(b));
      u.insert(dsu.find_set(a));
    }   
    else dsu.union_set(a, b);
  }
  
  int nc = dsu.not_cycle(u);
  
  cout << c << ' ' << nc << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// DSU.

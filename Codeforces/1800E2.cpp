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
    public:
        vector<int> ps;
        vector<int> size;
        map<int, multiset<char>> values;
    public:
        DSU(int N) : ps(N+1), size(N+1, 1){
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
            values[px].merge(values[py]);  
        }
};   
string solve(string s, string t, int n, int k) {
  DSU dsu(n+1);
  s = '$'+s; t = '$'+t;
  for(int i = 1; i <= n; ++i) {
    dsu.values[i].insert(s[i]);
  }
  for(int i = 1; i <= n; ++i) {
    if(i-k > 0) dsu.union_set(i, i-k);
    if(i-(k+1) > 0) dsu.union_set(i, i-k-1);
    if(i+k <= n) dsu.union_set(i, i+k);
    if(i+k+1 <= n) dsu.union_set(i, i+k+1);
  
  } 

  for(int i = 1; i <= n; ++i) {
    if(dsu.values[dsu.ps[i]].count(t[i])){
      auto it = dsu.values[dsu.ps[i]].find(t[i]);
      dsu.values[dsu.ps[i]].erase(it);
    }
    else return "NO";
  }
  return "YES";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    string s, t; cin >> s >>t;

    cout << solve(s, t, n, k) << '\n';
  }
}

// DSU, strings.

// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
class DSU{
    public:
        vector<ll> size;
        vector<ll> ps;

        DSU(ll n): size(n+1, 1), ps(n+1){
            iota(ps.begin(), ps.end(), 0);
        }
        ll find_set(ll x){
            return ps[x] == x ? x : ps[x] = find_set(ps[x]);
        }
        bool same_set(ll x, ll y){
            return find_set(x) == find_set(y);
        }
        void union_set(ll x, ll y){
            if(same_set(x, y)) return;

            ll psx = find_set(x);
            ll psy = find_set(y);

            if(size[psy] > size[psx])
                swap(psy, psx);
            ps[psy] = psx;
            size[psx] += size[psy];
            size[psy] = 0;
        }
        ll max_size(){
            return (ll)*max_element(size.begin(), size.end());
        }
        ull danger(){
            ll danger = 0;
            for(auto si : size)
                danger += si > 1 ? si-1 : 0;
            return danger;
        }
};


                
int main(){ 
    fastio;
    ll n, m;
    cin >> n >> m;
    DSU ccc(n);
    for(int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        ccc.union_set(a, b); 
    }
    ull ans = m >= 1 ? (ull)(1ULL<<(ccc.danger())) : 1;
    cout << ans << '\n';
    return 0;
}
// AC.

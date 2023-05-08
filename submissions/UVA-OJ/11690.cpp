// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
class DSU{
    public:
        vector<ll> ps;
        vector<pair<ll,ll>> sizesum;
        DSU(ll N) : ps(N+1), sizesum(N+1, {1,0}){
            iota(ps.begin(),ps.end(), 0);
        }
        ll find_set(ll x){
            return ps[x] == x ? ps[x] : find_set(ps[x]);
        }
        ll same_set(ll x, ll y){
            return find_set(x) == find_set(y);
        }
        void union_set(ll x , ll y){
            if(same_set(x, y)) return;

            ll px = find_set(x);
            ll py = find_set(y);

            if(sizesum[py].first >  sizesum[px].first) swap(px, py);
            
            ps[py] = px;
            sizesum[px].first += sizesum[py].first;
            sizesum[px].second += sizesum[py].second;
        }
        bool checkans(ll N){
            bool ans = true;
            for(int i = 0; i < N; ++i){
                //cout << "(" << i << " : " << sizesum[find_set(i)].second << ") ";
                
                if(sizesum[find_set(i)].second != 0) ans = false;
            }
            return ans;
        }
};
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;
        DSU dsu(n+1);
        for(int i = 1; i <= n; ++i){
            ll x;
            cin >> x;
            dsu.sizesum[i-1].second += x;
        }

        for(int i = 1; i <= m; ++i){
            ll a, b;
            cin >> a >> b;
            dsu.union_set(a, b);
        }

       cout << (dsu.checkans(n) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }

    return 0;
}
// AC.

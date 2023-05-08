// iagorrr ;) DSU
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
class DSU{
    private:
        vector<ll> size;
        vector<ll> ps;
    public:
        DSU(ll N) : size(N+1LL, 1), ps(N+1LL){
            iota(ps.begin(), ps.end(), 0);
        }
        ll find_set(ll x){
            return x == ps[x] ? ps[x] : ps[x] = find_set(ps[x]);
        }
        ll same_set(ll x, ll y){
            return find_set(x) == find_set(y);
        }
        void union_set(ll x, ll y){
            if(same_set(x, y)) return;


            ll px = find_set(x);
            ll py = find_set(y);

            if(size[py] > size[px]) swap(px, py);

            ps[py] = px;
            size[px] += size[py];
        }
        ll max_size(ll N){
            ll ans = -1;
            for(ll i = 1; i <= N; ++i) ans = max(ans, size[i]);
            return ans;
        }
        
};
int main(){ 
    fastio
    ll c, r;
    string buff;
    while(true){
        cin >> c >> r;
        if(c== 0 and r == 0) break;
        map<string, ll> ids;
        ll id = 1;
        DSU chain(c+1);
        
        for(int i = 1; i <= c; ++i){
            string s;
            cin >> s;
            ids[s] = id++;
        }

        for(int i = 1; i <= r; ++i){
            string a, b;
            cin >> a >> b;

            chain.union_set(ids[a], ids[b]);
        }

        ll ans = chain.max_size(c);
        cout << ans << '\n';
        
        getline(cin, buff);

    }
    return 0;
}
// AC.

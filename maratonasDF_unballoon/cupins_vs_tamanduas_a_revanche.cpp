// iagorrr ;)
/*
    Segtree:
        vetor a, onde a_i indica a primeira posição de um tamanduá com capacidade i 
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
map<char, ll> cv;

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
ll solve(string s, ll n, ll m){
    vector<ll> aux(m+1, LLONG_MAX);
    SegTree st(aux);

    ll ans = 0;
    vector<ll> tc; // capacidade de cada tamandua.
    vector<set<ll>> phist(m+1); // i-seima posicao contem posicao dos tamandua com capaciadde i.
    for(int i = 0; i <= m; ++i) phist[i].insert(LLONG_MAX);

    for(auto c : s){
        ll cc = cv[c]; // valor desse cupim.

        // checar qual a posição do primeiro tamandas que pode comer cc.
        ll p = st.RMQ(cc, m);
        if (p == LLONG_MAX){// não tem nem um com capacidade, inserir um novo.
            
            ll mr = m - cc; // capacidade de um tamandas inteiro após comer o cc.

            tc.push_back(mr); // manter registro da capaciadade dele.

            phist[mr].insert(ans); // colocar no historgrama do que possuem mr.

            st.update(mr, *phist[mr].begin()); // atualiza a pos do tamandas com essa capacidade se ele for o novo primeiro. 

            ans++;
        }
        else{ // existe um na posição p que pode comer, atualizar tudo.
             
            phist[tc[p]].erase(p); // o tamandas não tem mais a mesma capacidade remover de lá.
            st.update(tc[p], *phist[tc[p]].begin()); // atualizar com o primeiro que tiver essa capacidade.
            
            phist[tc[p]-cc].insert(p); // agora possui tc[p]-cc de capacidade, insere lá né.

            tc[p] -= cc; // atualiza no vetor mesmo.
            st.update(tc[p], *phist[tc[p]].begin()); // atualizar na seg os que tem essa mesma capacidade que ele.
        }
    }
    return ans;
}
int32_t main()
{
    fastio;
    ll x, y, z; cin >> x >> y >> z;

    ll m, n; cin >> m >> n;
    
    string s; cin >> s;

    cv['F'] = x; cv['A'] = y; cv['R'] = z;
        
    cout << solve(s, n, m) << '\n';
}

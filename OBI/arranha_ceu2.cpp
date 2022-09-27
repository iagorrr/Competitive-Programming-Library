// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

/*
    Solução com segment tree.
    Material : https://github.com/edsomjr/TEP

    * considera a raiz em 1.
*/

class SegmentTree {

    ll N;
    vector<ll> ns;
    public:
        // Inicialização recebe um vetor, define o tamanho e os valores através dos update.
        SegmentTree(const vector<ll>& xs) : N(xs.size()), ns(4*N,0){
            for(ll i = 0; i < (ll)xs.size(); ++i) update(i, xs[i]);
        }

        void update(ll i, ll value){
            update(1, 0, N-1, i, value);
        }
        ll RSQ(int a, int b){
            return RSQ(1, 0, N-1, a, b);
        }
        void show(){
            for(auto x : ns) cout << x << ' ';
            cout << '\n';
        }
    
    private:

        // Atualizar o valor do vetor.
        void update(ll node, ll L, ll R, ll i, ll value){
            if(i > R or i < L) return;
            
            // Aqui deve ser definida a operação.
            ns[node] = value + ns[node];

            if(L == R) return;

            // esquerda e direita.
            update(2*node, L, (L+R)/2, i, value);
            update(2*node+1, (L+R)/2 + 1, R, i, value);
        }

        // Responder o que está contido de a até b.
        ll RSQ (ll node, ll L, ll R, ll a, ll b){
            if(a > R or b < L) return 0; // intervalo fora do nó atual.

            if(a <= L and b >= R) return ns[node]; // o intervalo atual está contido dentro do que queremos.

            ll x = RSQ(node*2, L, (L+R)/2, a, b);
            ll y = RSQ(node*2 + 1, (L+R)/2 + 1, R, a, b);

            // oque foi possível pegar de cada lado.
            return x + y;
        }

        
};
int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;

    // inializar a árvore.
    SegmentTree st(arr);
    
    while(q--){
        int op;
        cin >> op;

        if(op == 0){   
            ll k, p;
            cin >> k >>  p;
            k--;
            ll value = p - arr[k];
            arr[k] = p;
            st.update(k, value);
            
        }
        else{
            ll k;
            cin >> k;
            k--;
            ll ans = st.RSQ(0, k);
            cout << ans << '\n';
        }   
    }

    return 0;
}
// wa

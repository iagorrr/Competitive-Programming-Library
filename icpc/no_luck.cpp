// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define INV(aaaa) for(auto &aaaa : aaaaaa) cin >> aaaaa;

#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

template <typename T>
class SegmentTree
{
private:
    int N;
    std::vector<T> ns, lazy;

public:
    SegmentTree(const std::vector<ll>& xs)
        : N(xs.size()), ns(40*N, 0), lazy(40*N, 0)
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, i, xs[i]);
    }

    void update(int a, int b, T value)
    {
        update(1, 0, N - 1, a, b, value);
    }

private:
    void update(int node, int L, int R, int a, int b, T value) {
        // Lazy propagation
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R)      // Se o nó não é uma folha, propaga
            {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        // [a, b] ∩ [L, R] = {∅}
        if (a > R or b < L)
            return;

        // [L, R] ⊂ [a, b] está contido; é subconjunto de
        if (a <= L and R <= b)
        {
            ns[node] += (R - L + 1) * value;

            if (L < R)
            {
                lazy[2*node] += value;
                lazy[2*node + 1] += value;
            }

            return;
        }
 
        update(2*node, L, (L + R)/2, a, b, value);
        update(2*node + 1, (L + R)/2 + 1, R, a, b, value);

        ns[node] = ns[2*node] + ns[2*node + 1];
    } 

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R) {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (a > R or b < L)
            return 0;

        if (a <= L and R <= b)
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }

public:
    void debug() {
      for(int i = 0; i <= N; ++i) {
        cout << "(" << i << ',' << RSQ(i, i) << ") ";
      }
      cout << '\n';
    }
};
void run(){
  ll n, k; cin >> n >> k;
  vll xs(n); for(auto &x : xs) cin >> x;

  vector<array<ll, 3>> infos(k);
  for(int i = 0; i < k; ++i) {
    for(int j = 0; j < 3; ++j) {
      cin >> infos[i][j];
    }
  }

  // marcar onde cada um comecou e termiou.
  vector<vector<ll>> observa(n+1);
  for(int i = 0; i < k; ++i) {
    auto [edicao, posicao, observou] = infos[i];
    if(posicao <= xs[edicao-1]) continue;
    ll comeco = min(edicao-1+1-1, n-1);
    ll fim = min(edicao-1+observou, n-1);
    observa[comeco].push_back(i+1);
    observa[fim].push_back(-(i+1));
  }

  ll maxvagas = *max_element(all(xs));
  vector<ll> aux(maxvagas+1, 0);
  SegmentTree <ll>segtree(aux);
  vector<pair<ll, ll>> ans(k);
  for(int i = 0; i < n; ++i) {
    ll vagasano = xs[i];
    segtree.update(0, vagasano, 1);

    for(auto obs : observa[i]){
      if(obs>0){
        obs = obs-1;
        ll posicao = infos[obs][1];
        // cout << "ans.first: " << ans[obs].first << '\n';
        ans[obs].first = segtree.RSQ(posicao, posicao);
        // segtree.debug();
        // cout << "poiscao: " << posicao << "ans.f: " << ans[obs].first << '\n';
      }
      else {
        obs++;
        obs = -obs;
        ll posicao = infos[obs][1];
        //cout << "ans.second: " << ans[obs].second << '\n';
        ans[obs].second = segtree.RSQ(posicao, posicao);
        // segtree.debug();
        // cout << "posicao: " << posicao << "ans.s: " << ans[obs].second << '\n';
      }
    }
  }

  for(int i = 0; i < k; ++i) {
    cout << ans[i].second - ans[i].first << '\n';
  }
}
int32_t main() {
  fastio;
  int t; t =1 ;
  // cin >> t;

  while(t--){
    run();
  }
}

// AC, segmente tree, RSQ

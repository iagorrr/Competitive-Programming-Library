// iagorrr :)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

int fastlog2(ll x){
  ull i = x;
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template<typename T>
class SparseTable {
  public:
    int N;
    int K;
    vector<vector<T>> st;
    SparseTable(vector<T> vs) : N((int)vs.size()), K(fastlog2(N) + 1), st(K+1, vector<T>(N+1)) {
      copy(vs.begin(), vs.end(), st[0].begin());

      for(int i = 1; i <= K; ++i)
        for(int j = 0; j + (1<<i) <= N; ++j)
          st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
    }
    T RMQ(int l, int r) {
      int i = fastlog2(r-l+1);
      return min(st[i][l], st[i][r-(1<<i)+1]);
    }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  vector<int> xs(n); for(auto &xsi : xs) cin >> xsi;
  SparseTable<int> st(xs); 
  int q; cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << st.RMQ(l, r) << '\n';
  }
}

// AC, sparse table, RMQ.

// iagorrr :)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

int fastlog2(ll x){
  return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
}

template<typename T>
class SparseTable {
  public:
    vector<vector<T>> st;
    int N;
    int K;
    SparseTable(vector<T> vs) : N((int)vs.size()), K(fastlog2(N) + 1), st(vector<vector<T>>(K+1, vector<T>(N))) {
      copy(vs.begin(), vs.end(), st[0]);

      for(int i = 1; i <= K; ++i)
        for(int j = 0; j + (1<<i) <= N; ++j)
          st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
    }
    T RMQ(int l, int r) {
      int i = fastlog2(r-l+1);
      return min(st[i][l], st[i][r-(1<<i)+1]);
    }
};

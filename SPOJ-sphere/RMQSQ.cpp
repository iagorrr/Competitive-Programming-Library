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
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  vector<int> xs(n); for(auto &xsi : xs) cin >> xsi;
  int K = fastlog2(n)+1;
  int st[K+1][n+1];
  copy(xs.begin(), xs.end(), st[0]);
  for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  
  int q; cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    int i = fastlog2(r - l + 1);
    int minimum = min(st[i][l], st[i][r - (1 << i) + 1]);
    cout << minimum << '\n';
  }
}

// AC, sparse table, RMQ.

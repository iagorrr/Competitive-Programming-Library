struct strPsum {
  ll n;
  ll k;
  vector<vll> psum;
  strPsum(const string &s) : n(s.size()), k(100), psum(k, vll(n + 1)) {
    for (ll i = 1; i <= n; ++i) {
      for (ll j = 0; j < k; ++j) {
        psum[j][i] = psum[j][i - 1];
      }
      psum[s[i - 1]][i]++;
    }
  }

  ll qtd(ll l, ll r, char c) {  // [0,n-1]
    return psum[c][r + 1] - psum[c][l];
  }
}

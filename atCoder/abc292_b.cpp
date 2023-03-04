// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

int32_t main(void){ fastio;
  int n; int q; cin >> n >> q;

  map<int,int> h;
  set<int> r;

  for(int i = 0; i < q; ++i) {
    int qi; cin >> qi;
    int x; cin >> x;
    if(qi == 1) {
      h[x]++; 
      if(h[x] >= 2) r.insert(x);
    }
    else if (qi == 2) {
      r.insert(x);
    }
    else {
      cout << (r.count(x) ? "Yes" : "No") << '\n';
    }
  }
}

// AC, implementation.

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

void solve(vi a, int n) {
  multiset<int> st;
  vi ans;

  for(int i = 0; i < n; ++i){
    // only take a number to the largest sequence if is larger or equal than the lowest selected.
    if(st.empty() or a[i] >= *st.begin())
      st.insert(a[i]);
    
    // if the lowest value is lower than the amount it adds to the denominator remove it.
    if((int)st.size() > *st.begin()) st.erase(st.begin());

    ans.push_back((int)st.size());
  }

  for(int i = 0; i < n; ++i)
    cout << ans[i] << " \n"[i==n-1];
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vi a(n); INV(a);
    solve(a, n);
  }
}

// AC, greedy, multiset

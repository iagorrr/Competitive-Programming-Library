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

void solve(string a, string b) {
  if(a.back() == b.back()){
    cout << "YES\n";
    cout << "*" << a.back() << "\n";
    return;
  }
  if(a.front() == b.front()) {
    cout << "YES\n";
    cout << a.front() << "*\n";
    return;
  }

  for(int i = 0; i < (int)a.size()-1; ++i){
    for(int j = 0; j < (int)b.size()-1; ++j){
      if(a[i] == b[j] and a[i+1] == b[j+1]){
        cout << "YES\n";
        cout << "*" << a[i] << a[i+1] << "*\n";
        return;
      }
    }
  }

  cout << "NO\n";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--){
    string a, b;
    cin >> a >> b;
    solve(a, b);
  }
}

// AC, implementation

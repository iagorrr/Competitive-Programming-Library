// iagorrr ;)
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void run(){
  string s; cin >> s;
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  cout << s << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC,string.

// iagorrr & thalisson ;)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
vector<PII> q;
int n, m, t;

inline int mapcircle(int x, int y) {
  if(y == 0) return x;
  if(x == n) return n + y;
  if(y == m) return m + n+(n-x);
  if(x == 0) return n+m+n + (m-y);
  return -1;
}

int main () { fastio;
  cin >> n >> m >> t;

  for(int i = 0; i < t; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int l = mapcircle(a,b);
    int r = mapcircle(x,y);
    if(l>r) swap(l, r);
    if(l!=-1 and r !=-1) q.emplace_back(r, l);
  }

  sort(all(q));
  stack<PII> st;
  for(auto [r, l] : q) {
    while(!st.empty() and st.top().second > l)
      st.pop();
    if(!st.empty() and st.top().first > l){
      cout << "N\n";
      return 0;
    }
    st.push({r, l});
  }

  cout << "Y\n";
  return 0;
}

// AC, implementation, math, geometry.

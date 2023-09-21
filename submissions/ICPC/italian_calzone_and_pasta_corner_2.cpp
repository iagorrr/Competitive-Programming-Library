// iagorrr ;)
#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define all(x) x.begin(), x.end()
vector<ll> check(100 * 100 + 1);
set<ll> notreached;
ll r, c;
vector<ll> adj(vector<vector<ll>> &grid, ll x, ll y) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  vector<ll> ans;
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < r and x2 > -1 and y2 < c and y2 > -1 and
        check[grid[x2][y2]] == 0) {
      ans.push_back(grid[x2][y2]);
      check[grid[x2][y2]] = 1;
    }
  }
  return ans;
}

array<pair<ll, ll>, 100 * 100 + 1> cord;

ll getmax(vector<vector<ll>> &grid, ll x, ll y) {
  priority_queue<ll, vector<ll>, greater<ll>> canreach;
  ll ans = 1;
  ll current = grid[x][y];
  vll temp = adj(grid, x, y);
  for (auto xi : temp)
    canreach.push(xi);

  while (!canreach.empty()) {
    ll closest = canreach.top();
    canreach.pop();
    while (!canreach.empty() and closest < current) {
      closest = canreach.top();
      canreach.pop();
    }
    if (closest < current)
      break;
    if(grid[x][y]) notreached.erase(closest);
    // isn't the same code.
    vector<ll> newadj = adj(grid, cord[closest].first, cord[closest].second);
    current = closest;
    for (auto xi : newadj){
      canreach.push(xi);
    }
    ans++;
  }

  return ans;
}
void solve() {
  cin >> r >> c;

  vector<vector<ll>> grid(r, vector<ll>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      ll x;
      cin >> x;
      grid[i][j] = x;
      cord[x] = make_pair(i, j);
    }
  }

  for(ll i = 1; i <= r*c;++i) notreached.insert(i);
  notreached.erase(1);
  ll ans = -1;
  fill(all(check), 0);
  check[1] = 1;
  ans = max(ans, getmax(grid, cord[1].first, cord[1].second));

  for(auto x : notreached){
      fill(all(check), 0);
      check[x] = 1;
      ans = max(ans, getmax(grid, cord[x].first, cord[x].second));
  }

  cout << ans << '\n';
}
int main() {
  fastio int t;
  t = 1;
  // cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }
}

// AC, flood fill.

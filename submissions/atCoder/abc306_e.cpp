// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, Q;
vector<ll> values;
set<pair<ll, ll>> kfirst;
set<pair<ll, ll>> candidates;
vector<char> used;
ll anssum = 0;

void put(ll p) { // put at the kfirst and remove from candidates
  used[p] = true;
  kfirst.insert({values[p], p});
  anssum += values[p];
  candidates.erase({values[p], p});
}

void remove(ll p) { // remove from kfirst and set as candidate
  used[p] = false;
  kfirst.erase({values[p], p});
  anssum -= values[p];
  candidates.insert({values[p], p});
}
void update(ll p, ll x) {
  if (used[p]) {
    remove(p);
  }

  candidates.erase({values[p], p});
  values[p] = x;
  candidates.insert({values[p], p});
}

pair<ll, ll> best_candidate() {
  if (candidates.size())
    return *prev(candidates.end());
  else
    return {LLONG_MIN, LLONG_MIN};
}
void whileput() {
  // there is less than k in the kfirst
  while ((int)kfirst.size() < K) {
    auto it = *prev(candidates.end());
    put(it.second);
  }

  // if there is a better candidate than the current used
  while (true) {
    auto it = best_candidate();
    if (it.first > kfirst.begin()->first) {
      put(it.second);
      remove(kfirst.begin()->second);
    } else {
      break;
    }
  }
}
int main(void) {
  cin >> N >> K;
  values = vector<ll>(N, 0);
  used = vector<char>(N, false);
  for (int i = 0; i < N; ++i) {
    candidates.insert({0, i});
  }

  cin >> Q;
  while (Q--) {
    ll x, y;
    cin >> x >> y;
    x--;
    update(x, y);

    whileput();
    cout << anssum << '\n';
  }
}
// AC, data structures, greedy

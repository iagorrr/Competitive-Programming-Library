#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

int to_int(char c) { return c - '0'; }

void run() {
  string s;
  cin >> s;
  vector<int> divs;
  if (to_int(s.back()) % 2 == 0) divs.push_back(2);

  ll sum = 0;
  for (auto c : s) sum += to_int(c);
  if (sum % 3 == 0) divs.push_back(3);

  if (divs.size() == 2) divs.push_back(6);

  if (s.size() == 1) {
    auto x = to_int(s[0]);
    if (x % 4 == 0) divs.push_back(4);
  } else {
    auto x = to_int(s[len(s) - 2]) * 10 + to_int(s.back());
    if (x % 4 == 0) divs.push_back(4);
  }
  if (s.back() == '0' or s.back() == '5') divs.push_back(5);

  sort(all(divs));
  for (int i = 0; i < len(divs); i++)
    cout << divs[i] << " \n"[i == len(divs) - 1];
  if (divs.empty()) cout << "-1\n";
}

int32_t main() {
  fastio;
  int t = 1;
  cin >> t;
  while (t--) run();
}

// AC, math

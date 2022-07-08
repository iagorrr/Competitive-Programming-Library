#include <bits/stdc++.h>
using namespace std;

#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Segment tree point update range query/Query hash (top down).cpp"

auto solve() {
  computepows();
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> intS;
  for (auto c : S) intS.push_back(c);
  SegTree seg(intS.size());
  for (int i = 0; i < (int)intS.size(); i++) {
    seg.assign(i, intS[i]);
  }
  reverse(all(intS));
  SegTree rseg(intS.size());

  for (int i = 0; i < (int)intS.size(); i++) {
    rseg.assign(i, intS[i]);
  }

  while (Q--) {
    int o;
    cin >> o;
    switch (o) {
      case 1:
        char c;
        int p;
        cin >> p >> c;
        p--;
        seg.assign(p, c);
        rseg.assign(N - p - 1, c);
        break;
      case 2:
        int l, r;
        cin >> l >> r;
        l--, r--;
        ll a = seg.query(l, r).hash;
        ll b =
            rseg.query(N - r - 1, N - l - 1).hash;

        cout << (a == b ? "YES" : "NO") << endl;
        break;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  solve();
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN(2'00'000);
int N, M;
int XS[MAXN], CS[MAXN], POS[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> XS[i];
    XS[i]--;
    POS[XS[i]] = i;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int ai = XS[i];
    if (ai) {
      CS[ai] = POS[ai - 1] > POS[ai];
    } else
      CS[ai] = 1;

    ans += CS[ai];
  }

  while (M--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    int v1 = XS[a], v2 = XS[b];
    swap(XS[a], XS[b]);
    swap(POS[v1], POS[v2]);

    for (int vi = v1 - 1; vi <= v1 + 1; vi++) {
      if (vi < 0 or vi == N) continue;
      ans -= CS[vi];
      if (vi)
        CS[vi] = POS[vi - 1] > POS[vi];
      else
        CS[vi] = 1;
      ans += CS[vi];
    }

    for (int vi = v2 - 1; vi <= v2 + 1; vi++) {
      if (vi < 0 or vi == N) continue;
      ans -= CS[vi];
      if (vi)
        CS[vi] = POS[vi - 1] > POS[vi];
      else
        CS[vi] = 1;
      ans += CS[vi];
    }

    cout << ans << '\n';
  }
}

// AC, ad-hoc

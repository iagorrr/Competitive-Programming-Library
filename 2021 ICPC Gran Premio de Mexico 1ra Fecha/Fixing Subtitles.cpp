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

void foda(int &h, int &m, int &s, int &ms, int d1, int d2) {
  ms += d2;
  s += ms / 1000;
  ms = ms % 1000;

  s += d1;
  m += s / 60;
  s = s % 60;

  h += m / 60;
  m = m % 60;

  h = h % 24;
}
void run() {
  int n;
  int d1, d2;
  scanf("%d %d.%d", &n, &d1, &d2);

  for (int i = 0; i < n; i++) {
    int id;
    scanf("%d", &id);

    int h1, m1, s1, ms1;
    int h2, m2, s2, ms2;
    scanf("%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d", &h1, &m1, &s1, &ms1,
          &h2, &m2, &s2, &ms2);

    foda(h1, m1, s1, ms1, d1, d2);
    foda(h2, m2, s2, ms2, d1, d2);

    printf("%d\n", id);
    printf("%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n", h1, m1, s1, ms1, h2,
           m2, s2, ms2);

    cin.ignore();
    string s;
    getline(cin, s);
    while (not s.empty()) {
      cout << s << '\n';
      getline(cin, s);
    }
    cout << '\n';
  }
}
int32_t main() {
  // fastio;
  int t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, implementation

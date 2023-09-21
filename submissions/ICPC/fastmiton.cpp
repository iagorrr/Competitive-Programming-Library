#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  // 0 - esq 1 -dir
  int saca = 0;
  int pte = 0, ptd = 0;
  int je = 0, jd = 0;

  int n = s.size();
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (s[i] == 'Q') {
      if (je + jd >= 3 or je >= 2 or jd >= 2) { // winer
        if (je > jd) {
          cout << je << " (winner) - " << jd << '\n';
        } else {
          cout << je << " - " << jd << " (winner)" << '\n';
        }
      } else {
        cout << je << " (" << pte << (saca == 0 ? "*" : "") << ") - " << jd
             << " (" << ptd << (saca == 1 ? "*" : "") << ")\n";
      }
      continue;
    }

    if (je + jd >= 3) {
      break;
    }
    if (saca) { // dir
      if (c == 'S') {
        ptd++;
      } else {
        saca = 0;
        pte++;
      }
    } else {
      if (c == 'S') {
        pte++;
      } else {
        saca = 1;
        ptd++;
      }
    }

    // ganaha partida.
    if ((pte >= 5 and pte - ptd >= 2) or (pte == 10)) {
      je++;
      pte = 0;
      ptd = 0;
      saca = 0;
    }
    if ((ptd >= 5 and ptd - pte >= 2) or (ptd == 10)) {
      jd++;
      pte = 0;
      ptd = 0;
      saca = 1;
    }
  }
}
int main() {
  int t = 1;

  while (t--) {
    solve();
  }
}
// AC, implementation, simulate

// iagorrr ;)
#include <bits/stdc++.h>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b >> c;
  int ans = a + b + c;
  if (a + b + c >= 500)
    ans -= 100;
  if (a + b >= 500)
    ans = min(ans, (a + b - 100) + (c >= 500 ? c - 100 : c));
  if (a + c >= 500)
    ans = min(ans, (a + c - 100) + (b >= 500 ? b - 100 : b));
  if (b + c >= 500)
    ans = min(ans, (b + c - 100) + (a >= 500 ? a - 100 : a));
  if (a >= 500 and b >= 500 and c >= 500)
    ans = min(ans, a + b + c - 300);
  cout << ans << '\n';

  return 0;
}

// AC, implementation.

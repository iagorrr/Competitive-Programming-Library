#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;

const int oo = (int)1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll calc;
  cin >> calc;

  while (true) {

    cout << calc << "\n";

    if (calc < 10)
      break;

    calc = (calc / 10) * 3 + (calc % 10);
  }
}

// AC, math, implementation

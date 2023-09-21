#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (auto c : s)
    (c == 'X' ? a++ : b++);

  dbg(a, b);
  if (b > a or abs(b - a) == 3)
    cout << "?\n";
  else if (s[0] == s[1] or s[1] == s[2])
    cout << (s[1] == 'O' ? "Bob" : "Alice") << '\n';
  else
    cout << "*\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

// AC, game

/*8<
  @Description:
    Recursive formula:
      $ C_0 = C_1 = 1 $

      $ C_n = \sum_{k = 0}^{n-1} C_k C_{n-1-k} ,
{n} \geq 2 $

      Analytical formula:
      $ C_n = \binom{2n}{n} - \binom{2n}{n-1} =
      \frac{1}{n + 1} \binom{2n}{n} , {n} \geq 0 $

      The first few numbers Catalan numbers, $C_n$
      (starting from zero): $1, 1, 2, 5, 14, 42,
  132, 429, 1430, \ldots$

      The Catalan number $C_n$ is the solution
for: \begin{itemize}

        \item Number of correct bracket sequence
      consisting of $n$ opening and $n$ closing
      brackets. \item The number of rooted full
  binary trees with $n + 1$ leaves (vertices are
not numbered). A rooted binary tree is full if
  every vertex has either two children or no
  children. \item The number of ways to completely
      parenthesize $n + 1$ factors. \item The
number of triangulations of a convex polygon with
$n + 2$ sides (i.e. the number of partitions of
polygon into disjoint triangles by using the
  diagonals). \item The number of ways to connect
  the $2n$ points on a circle to form $n$ disjoint
  chords. \item The number of non-isomorphic full
  binary trees with $n$ internal nodes (i.e. nodes
  having at least one son). \item The number of
  monotonic lattice paths from point $(0, 0)$ to
  point $(n, n)$ in a square lattice of size $n
  \times n$, which do not pass above the main
  diagonal (i.e. connecting $(0, 0)$ to $(n, n)$).
  \item Number of permutations of length $n$ that
  can be stack sorted (i.e. it can be shown that
the rearrangement is stack sorted if and only if
    there is no such index $i < j < k$, such that
  $a_k < a_i < a_j$ ). \item The number of
  non-crossing partitions of a set of $n$
elements. \item The number of ways to cover the
ladder $1 \ldots n$ using $n$ rectangles (The
ladder consists of $n$ columns, where $i^{th}$
column has a height $i$).

    \end{itemize}

>8*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
ll extGcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  } else {
    ll g = extGcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  }
}
ll inv(ll a) {
  ll inv_x, y;
  extGcd(a, MOD, inv_x, y);
  return (inv_x % MOD + MOD) % MOD;
}
const int MAXN = 4000010;
ll fat[MAXN], ifat[MAXN];
void init() {
  fat[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fat[i] = (fat[i - 1] * i) % MOD;
  ifat[MAXN - 1] = inv(fat[MAXN - 1]);
  for (int i = MAXN - 2; i >= 0; i--)
    ifat[i] = (ifat[i + 1] * (i + 1)) % MOD;
  assert(ifat[0] == 1);
}
ll C(int n, int k) {
  if (k > n) return 0;
  return (fat[n] *
          ((ifat[k] * ifat[n - k]) % MOD)) %
         MOD;
}
ll catalan(int n) {
  return (C(2 * n, n) - C(2 * n, n - 1) + MOD) %
         MOD;
}
ll f(int x1, int y1, int x2, int y2) {
  int y = y2 - y1, x = x2 - x1;
  if (y < 0 or x < 0) return 0;
  return C(x + y, x);
}
// o = number of '(', c = number of ')', k = fixed
// prefix of '(' extra Catalan Generalization,
// open[i] >= close[i] for each 0 <= i < o + c + k
// where open[i] is number of '(' in prefix until
// i and close[i] is number of ')'
ll catalan2(int o, int c, int k) {
  int x = o + k - c;
  if (x < 0) return 0;
  return (f(k, 0, o + k, c) -
          f(k, 0, o + k - x - 1, c + x + 1) +
          MOD) %
         MOD;
}

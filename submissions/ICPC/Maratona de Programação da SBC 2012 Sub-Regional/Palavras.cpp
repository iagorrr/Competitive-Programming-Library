#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

// Trie
//
// trie T() constroi uma trie para o alfabeto das letras
// minusculas trie T(tamanho do alfabeto, menor caracter)
// tambem pode ser usado
//
// T.insert(s) - O(|s|*sigma)
// T.erase(s) - O(|s|)
// T.find(s) retorna a posicao, 0 se nao achar - O(|s|)
// T.count_pref(s) numero de strings que possuem s como
// prefixo - O(|s|)
//
// Nao funciona para string vazia

struct trie {
  vi2d to;
  vi end, pref;
  int sigma;
  char norm;

  trie(int sigma_ = 26, char norm_ = 'a')
    : sigma(sigma_), norm(norm_) {
    to = {vector<int>(sigma)};
    end = {0}, pref = {0};
  }

  bool is_end(int node) { return end[node] != 0; }

  int next(int node, char key) {
    return to[node][key - norm];
  }

  void insert(const string &s) {
    int x = 0;
    for (auto c : s) {
      int &nxt = to[x][c - norm];
      if (!nxt) {
        nxt = len(to);
        to.push_back(vi(sigma));
        end.emplace_back(0), pref.emplace_back(0);
      }
      x = nxt, pref[x]++;
    }
    end[x]++, pref[0]++;
  }
  void erase(const string &s) {
    int x = 0;
    for (char c : s) {
      int &nxt = to[x][c - norm];
      x = nxt, pref[x]--;
      if (!pref[x]) nxt = 0;
    }
    end[x]--, pref[0]--;
  }
  int find(const string &s) {
    int x = 0;
    for (auto c : s) {
      x = to[x][c - norm];
      if (!x) return 0;
    }
    return x;
  }
  int count_pref(const string &s) { return pref[find(s)]; }
};

const int MAXN(21);
trie A, B;
char vis[MAXN * MAXN + 100][MAXN * MAXN + 100];
int N, M;

bool dfs(int a, int b) {
  if (A.is_end(a) and B.is_end(b)) return true;

  if (vis[a][b]) return false;

  vis[a][b] = true;

  bool ans = false;

  if (A.next(a, '0') and B.next(b, '0'))
    ans |= dfs(A.next(a, '0'), B.next(b, '0'));

  if (A.next(a, '1') and B.next(b, '1'))
    ans |= dfs(A.next(a, '1'), B.next(b, '1'));

  if (A.is_end(a)) {
    if (B.next(b, '1') and A.next(0, '1'))
      ans |= dfs(A.next(0, '1'), B.next(b, '1'));

    if (B.next(b, '0') and A.next(0, '0'))
      ans |= dfs(A.next(0, '0'), B.next(b, '0'));
  }

  if (B.is_end(b)) {
    if (A.next(a, '1') and B.next(0, '1'))
      ans |= dfs(A.next(a, '1'), B.next(0, '1'));

    if (A.next(a, '0') and B.next(0, '0'))
      ans |= dfs(A.next(a, '0'), B.next(0, '0'));
  }
  return ans;
}

auto solve() {
  A = trie(3, '0'), B = trie(4, '0');
  memset(vis, 0, sizeof vis);

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    A.insert(s);
  }

  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    B.insert(s);
  }

  bool ans = false;
  if (A.next(0, '0') and B.next(0, '0'))
    ans |= dfs(A.next(0, '0'), B.next(0, '0'));

  if (A.next(0, '1') and B.next(0, '1'))
    ans |= dfs(A.next(0, '1'), B.next(0, '1'));

  cout << "NS"[ans] << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> t;

  while (cin >> N >> M) {
    solve();
  }
}

// AC, strings, trie

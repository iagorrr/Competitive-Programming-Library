#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAXN(2'00'000);
int N;
int ST[MAXN << 1], XS[MAXN];

struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &nl, Node &nr) {
  Node m;
  m.value = nl.value + nr.value;
  return m;
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int n) : n(n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};

int main() {
  cin >> N;
  SegTree st(N);
  for (int i = 0; i < N; i++) {
    st.assign(i, 1);
    cin >> XS[i];
  }

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;

    int l = 0, r = N - 1;
    int ans = N;

    while (l <= r) {
      int mid = midpoint(l, r);
      int sum = st.query(0, mid).value;

      if (sum >= p) {
        ans = min(ans, mid);
        r = mid - 1;
      } else
        l = mid + 1;
    }

    cout << XS[ans] << " \n"[i == N - 1];
    st.assign(ans, 0);
  }
}

/*
 * AC
 * Segtree
 * Range sum query
 * Binary Search
 * https://cses.fi/problemset/task/1749/
 * */

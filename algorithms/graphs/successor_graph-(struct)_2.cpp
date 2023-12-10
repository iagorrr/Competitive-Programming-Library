const int MAXLG2 = 31;
struct FunctionalGraph {
  int n;
  vi g;
  vi2d bl;

  FunctionalGraph(int _n)
    : n(_n), g(n), bl(n, vi(MAXLG2)){};

  FunctionalGraph(const vi &_g)
    : n(len(_g)), g(_g), bl(n, vi(MAXLG2)){};

  void build() {
    for (int i = 0; i < n; i++) {
      bl[i][0] = g[i];
    }
    for (int k = 1; k < MAXLG2; k++) {
      for (int i = 0; i < n; i++) {
        bl[i][k] = bl[bl[i][k - 1]][k - 1];
      }
    }
  }

  int kth_pos(int u, ll k) const {
    for (ll i = 0; i < MAXLG2; i++)
      if (k & (1 << i)) u = bl[u][i];

    return u;
  }
};

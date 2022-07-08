#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Merge sort tree.cpp"

int32_t main() {
  ios_base::sync_with_stdio();
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vll XS(N);
  for (auto& xi : XS) cin >> xi;
  vll ys(N);
  map<ll, ll> appears;
  const ll OO = 1e9;
  rrep(i, N - 1, 0 - 1) {
    ll xi = XS[i];
    ys[i] = appears.count(xi) ? appears[xi] : OO;
    appears[xi] = i;
  }
  MergeSortTree<ll> mst(ys);
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int sz = (r - l + 1);
    cout << sz - mst.inrange(l, r, 0, r) << endl;
  }
}

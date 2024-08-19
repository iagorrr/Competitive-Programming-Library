#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Segment tree point update range query/Query sum (bottom up).cpp"

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> xs(n);
  set<ll> ordered;
  for (auto& xi : xs) {
    cin >> xi;
    ordered.emplace(xi);
  }

  map<ll, int> id;
  int curid = 0;
  for (auto xi : ordered) {
    id[xi] = curid++;
  }

  ll ans = 0;

  SegTree st(n);
  SegTree hs(n);
  for (auto& xi : xs) {
    auto xiid = id[xi];
    ll qtd = hs.query(0, xiid).value;
    ll v = st.query(0, xiid).value;
    ans = ans + qtd * xi - v;

    auto p = hs.query(xiid, xiid);
    p.value++;
    hs.assign(xiid, p);

    auto p2 = st.query(xiid, xiid);
    p2.value += xi;
    st.assign(xiid, p2);
  }

  cout << ans << '\n';
}

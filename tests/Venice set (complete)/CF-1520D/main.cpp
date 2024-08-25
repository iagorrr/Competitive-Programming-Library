#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Venice set (complete).cpp"

void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
/*8<==========================================>8*/

void run() {
  int N;
  cin >> N;
  vi XS(N);
  for (auto &xi : XS) cin >> xi;
  VeniceSet st;
  ll ans = 0;
  trav(xi, XS) {
    dbg(st.pq, st.acc);
    dbg(st.count(xi), xi);
    ans += st.count(xi);
    st.add_element(xi);
    st.update_all(1);
  }
  cout << ans << endl;
}

/*8<
>8*/

#include "../../../content/Contest/template.cpp"
#include "../../../content/Data Structures/Mex with update.cpp"

int32_t main() {
  int N, Q;
  cin >> N >> Q;
  vi AS(N);
  for (auto& ai : AS) cin >> ai;
  Mex mex(AS);
  rep(q, 0, Q) {
    int i, x;
    cin >> i >> x;
    i--;
    mex.rmv(AS[i]);
    mex.add(x);
    AS[i] = x;
    cout << mex() << endl;
  }
}

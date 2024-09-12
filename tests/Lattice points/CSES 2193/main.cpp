#include "../../../content/Geometry/Lattice points.cpp"

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point<ll>> pts(n);
  for (auto& [x, y] : pts) cin >> x >> y;
  auto [inside, bounds] = latticePoints(pts);
  cout << inside << ' ' << bounds << '\n';
}

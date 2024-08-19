ll cross(ll x1, ll y1, ll x2, ll y2) {
  return x1 * y2 - x2 * y1;
}

ll polygonArea(vector<pll> &pts) {
  ll ats = 0;
  for (int i = 2; i < len(pts); i++)
    ats +=
        cross(pts[i].first - pts[0].first,
              pts[i].second - pts[0].second,
              pts[i - 1].first - pts[0].first,
              pts[i - 1].second - pts[0].second);
  return abs(ats / 2ll);
}

ll boundary(vector<pll> &pts) {
  ll ats = pts.size();
  for (int i = 0; i < len(pts); i++) {
    ll deltax = (pts[i].first -
                 pts[(i + 1) % pts.size()].first);
    ll deltay =
        (pts[i].second -
         pts[(i + 1) % pts.size()].second);
    ats += abs(__gcd(deltax, deltay)) - 1;
  }
  return ats;
}

pll latticePoints(vector<pll> &pts) {
  ll bounds = boundary(pts);
  ll area = polygonArea(pts);
  ll inside = area + 1ll - bounds / 2ll;

  return {inside, bounds};
}

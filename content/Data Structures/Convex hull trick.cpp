/*8<{=====~ BEGIN CONVEX HULL TRICK ~=========>8*/
/*8<
  @Title:

    Convex Hull Trick / Line Container

  @Description:

    Container where you can add lines of the
    form $mx + b$, and query the maximum value
    at point $x$.

  @Usage:

    $insert\_line(m, b)$ inserts the line
    $m \cdot x + b$ in the container.


    $eval(x)$ find the highest value among
    all lines in the point $x$.

  @Time:

    Eval and insert in $O(\log{N})$

>8*/

const ll LLINF = 1e18;
const ll is_query = -LLINF;
struct Line {
  ll m, b;
  mutable function<const Line *()> succ;
  bool operator<(const Line &rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line *s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct Cht : public multiset<Line> {  // maintain
                                      // max m*x+b
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (ld)(x->b - y->b) * (z->m - y->m) >=
           (ld)(y->b - z->b) * (y->m - x->m);
  }
  void insert_line(ll m,
                   ll b) {  // min -> insert (-m,-b) -> -eval()
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
};

/*8<=========================================}>8*/

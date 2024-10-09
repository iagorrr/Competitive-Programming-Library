/*8<{=====~ BEGIN LICHAO TREE DYNAMIC ~=======>8*/
/*8<
  @Title:

    Lichao Tree (dynamic)

  @Description:

    Lichao Tree that creates the nodes
    dynamically, allowing to query and
    update from range $[MAXL, MAXR]$

  @Usage:
    \begin{compactitem}
      \item $query(x)$ : find the highest point
      among all lines in the structure


      \item $add(a, b)$ : add a line of form
      $y = ax + b$ in the structure


      \item $addSegment(a, b, l, r)$ : add a line
      segment of form $y = ax + b$ which covers
      from range $[l, r]$
    \end{compactitem}


  @Time:

    $O(\log{N})$
>8*/

template <typename T = ll, T MAXL = 0, T MAXR = 1 '000' 000'001>
struct LiChaoTree {
  static const T inf = -numeric_limits<T>::max() / 2;
  bool first_best(T a, T b) { return a > b; }
  T get_best(T a, T b) { return first_best(a, b) ? a : b; }
  struct line {
    T m, b;
    T operator()(T x) { return m * x + b; }
  };
  struct node {
    line li;
    node *left, *right;
    node(line _li = {0, inf}) : li(_li), left(nullptr), right(nullptr) {}
    ~node() {
      delete left;
      delete right;
    }
  };
  node *root;
  LiChaoTree(line li = {0, inf}) : root(new node(li)) {}
  ~LiChaoTree() { delete root; }
  T query(T x, node *cur, T l, T r) {
    if (cur == nullptr) return inf;
    if (x < l or x > r) return inf;
    T mid = midpoint(l, r);
    T ans = cur->li(x);
    ans = get_best(ans, query(x, cur->left, l, mid));
    ans = get_best(ans, query(x, cur->right, mid + 1, r));
    return ans;
  }
  T query(T x) { return query(x, root, MAXL, MAXR); }
  void add(line li, node *&cur, T l, T r) {
    if (cur == nullptr) {
      cur = new node(li);
      return;
    }
    T mid = midpoint(l, r);
    if (first_best(li(mid), cur->li(mid))) swap(li, cur->li);
    if (first_best(li(l), cur->li(l))) add(li, cur->left, l, mid);
    if (first_best(li(r), cur->li(r))) add(li, cur->right, mid + 1, r);
  }
  void add(T m, T b) { add({m, b}, root, MAXL, MAXR); }
  void addSegment(line li, node *&cur, T l, T r, T lseg, T rseg) {
    if (r < lseg || l > rseg) return;
    if (cur == nullptr) cur = new node;
    if (lseg <= l && r <= rseg) {
      add(li, cur, l, r);
      return;
    }
    T mid = midpoint(l, r);
    if (l != r) {
      addSegment(li, cur->left, l, mid, lseg, rseg);
      addSegment(li, cur->right, mid + 1, r, lseg, rseg);
    }
  }
  void addSegment(T a, T b, T l, T r) {
    addSegment({a, b}, root, MAXL, MAXR, l, r);
  }
};

/*8<{======~ END LICHAO TREE DYNAMIC ~========>8*/

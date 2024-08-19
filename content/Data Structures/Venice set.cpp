/*8<==========================================>8*/
/*8<
  @Title:

    Venice Set

  @Description:

    A container that you can insert $q$ copies
    of element $e$, increment every element in
    the contaiver in $x$, query which is the
    best element and it's quantity and also
    remove $k$ copies of the greatest element.


  @Time:

    \begin{compactitem}
      \item add elment $O(\log{N})$
      \item remove $O(\log{N})$
      \item update: $O(1)$
      \item query $O(1)$
    \end{compactitem}

>8*/
template <typename T = ll>
struct VeniceSet {
  using T2 = pair<T, ll>;
  priority_queue<T2, vector<T2>, greater<T2>> pq;

  T acc;
  VeniceSet() : acc() {}

  void add_element(const T &e, const ll q) {
    pq.emplace(e - acc, q);
  }

  void update_all(const T &x) { acc += x; }

  T2 best() {
    auto ret = pq.top();
    ret.first += acc;
    return ret;
  }

  void pop() { pq.pop(); }

  void pop_k(int k) {
    auto [e, q] = pq.top();
    pq.pop();
    q -= k;
    if (q) pq.emplace(e, q);
  }
};

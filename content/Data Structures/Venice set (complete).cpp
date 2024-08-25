/*8<
  @Title: Venice Set (complete)

  @Description:

    A container which you can insert elements
    update all at once and also make a few
    queries

  @Usage:
    \begin{compactitem}
      \item $add\_element(e,q)$: adds $q$ copies
      of $e$, if no $q$ is provided adds a single
      one

      \item $update\_all(x)$: increment every
value by $x$

      \item $erase(e)$: removes every copy
      of $e$, and returns how much was
      removed.


      \item $count(e)$: returns the number
      of  $e$ in the container

      \item $high()$/$low()$: returns the
      hightest/lowest element, and it's
      quantity

      \item $pop\_low(q)$/$pop\_high(q)$: removes
      $q$ copies of the lowest/highest elements
      if no $q$ is provided removes all copies
      of the lowest/highest element.

    \end{compactitem}

    You may answer which is the $K-th$ value and
    it's quantity using an $ordered\_set$.

    Probably works with other operations

  @Time:

    Considering $N$ the number of distinct
    numbers in the container

    \begin{compactitem}
      \item $add\_element(e,q)$: $O(\log{(N))}$

      \item $update\_all(x)$:$O(1)$

      \item $erase(e)$: $O(\log{(N))}$


      \item $count(e)$: $O(\log{(N))}$

      \item $high()$/$low()$: $O(1)$

      \item $pop\_low(q)$/$pop\_high(q)$: worst
      case is $O(N \cdot \log{(N)})$ if you
      remove all elements and so on...

    \end{compactitem}

  @Warning:

    There is no error handling if you try to
    $pop$ more elements than exists or related
    stuff
>8*/
struct VeniceSet {
  set<pll> st;
  ll acc;
  VeniceSet() : acc() {}

  ll add_element(ll e, ll q = 1) {
    q += erase(e);
    e -= acc;
    st.emplace(e, q);
    return q;
  }

  void update_all(ll x) { acc += x; }

  ll erase(ll e) {
    e -= acc;
    auto it = st.lb({e, LLONG_MIN});
    if (it == end(st) || (*it).first != e)
      return 0;
    ll ret = (*it).second;
    st.erase(it);
    return ret;
  }

  ll count(ll x) {
    x -= acc;
    auto it = st.lb({x, LLONG_MIN});
    if (it == end(st) || (*it).first != x)
      return 0;
    return (*it).second;
  }

  pll high() { return *rbegin(st); }

  pll low() { return *begin(st); }

  void pop_high(ll q = -1) {
    if (q == -1) q = high().second;
    while (q) {
      auto [e, eq] = high();
      st.erase(prev(end(st)));
      if (eq > q) add_element(e, eq - q);
      q = max(0ll, q - eq);
    }
  }

  void pop_low(ll q = -1) {
    if (q == -1) q = low().second;
    while (q) {
      auto [e, eq] = low();
      st.erase(st.begin());
      if (eq > q) add_element(e, eq - q);
      q = max(0ll, q - eq);
    }
  }
};

/*8<{=============~ BEGIN MEX ~===============>8*/
/*8<
  @Title:

    Mex with update

  @Description:

    This DS allows you to mantain an array of
    elments, insert, and remove, and query
    the MEX at any time.

  @Usage:

    \begin{compactitem}
      \item \textbf{$Mex(mxsz)$}: Initialize
      the DS, $mxsz$ must be the maximum number
      of elements that the structure may have.

      \item \textbf{$add(x)$}: just adds one
      copy of $x$.

      \item \textbf{$rmv(x)$}: just remove a copy
      of $x$.

      \item \textbf{$operator()$}: returns the
      MEX.
    \end{compactitem}

    @Time:

      \begin{compactitem}
        \item \textbf{$Mex(mxsz)$}:
$O(\log{mxsz})$

        \item \textbf{$add(x)$}: $O(\log{mxsz})$

        \item \textbf{$rmv(x)$}: $O(\log{mxsz})$

        \item \textbf{$operator()$}: $O(1)$
      \end{compactitem}

>8*/

struct Mex {
    int mx_sz;
    vi hs;
    set<int> st;

    Mex(int _mx_sz) : mx_sz(_mx_sz), hs(mx_sz + 1) {
        auto it = st.begin();
        rep(i, 0, mx_sz + 1) it = st.insert(it, i);
    }

    void add(int x) {
        if (x > mx_sz) return;
        if (!hs[x]++) st.erase(x);
    }

    void rmv(int x) {
        if (x > mx_sz) return;
        if (!--hs[x]) st.emplace(x);
    }

    int operator()() const { return *st.begin(); }

    /*
      Optional, you can just create with size
      len(xs) add N elements :D
    */
    Mex(const vi &xs, int _mx_sz = -1) : Mex(~_mx_sz ? _mx_sz : len(xs)) {
        for (auto xi : xs) add(xi);
    }
};

/*8<===============~ END MEX ~===============}>8*/

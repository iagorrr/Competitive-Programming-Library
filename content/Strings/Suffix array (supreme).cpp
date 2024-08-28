// Créditos: ShahjalalShohag
// O(N)
struct SA {
  int n;
  string s;
  vector<int> sa, lcp, pos;
  // RMQ<int> rmq;

  void induced_sort(vector<int> &vec, int val,
                    vector<int> &sa,
                    vector<bool> &sl,
                    vector<int> &lms) {
    vector<int> l(val), r(val);
    for (int c : vec) {
      if (c + 1 < val) l[c + 1]++;
      r[c]++;
    }
    partial_sum(l.begin(), l.end(), l.begin());
    partial_sum(r.begin(), r.end(), r.begin());
    fill(sa.begin(), sa.end(), -1);
    for (int i = lms.size() - 1; i >= 0; i--)
      sa[--r[vec[lms[i]]]] = lms[i];
    for (int i : sa) {
      if (i >= 1 && sl[i - 1])
        sa[l[vec[i - 1]]++] = i - 1;
    }
    fill(r.begin(), r.end(), 0);
    for (int c : vec) r[c]++;
    partial_sum(r.begin(), r.end(), r.begin());
    for (int k = sa.size() - 1, i = sa[k]; k >= 1;
         --k, i = sa[k]) {
      if (i >= 1 && !sl[i - 1])
        sa[--r[vec[i - 1]]] = i - 1;
    }
  }

  vector<int> build_sa(vector<int> &vec,
                       int val) {
    int n = vec.size();
    vector<int> sa(n), lms;
    vector<bool> sl(n);
    sl[n - 1] = false;
    for (int i = n - 2; i >= 0; i--) {
      sl[i] =
          (vec[i] > vec[i + 1] ||
           (vec[i] == vec[i + 1] && sl[i + 1]));
      if (sl[i] && !sl[i + 1])
        lms.push_back(i + 1);
    }
    reverse(lms.begin(), lms.end());
    induced_sort(vec, val, sa, sl, lms);
    vector<int> new_lms(lms.size()),
        lms_vec(lms.size());
    for (int i = 0, k = 0; i < n; i++) {
      if (!sl[sa[i]] && sa[i] >= 1 &&
          sl[sa[i] - 1])
        new_lms[k++] = sa[i];
    }
    int cur = 0;
    sa[n - 1] = cur;
    for (int k = 1; k < (int)new_lms.size();
         k++) {
      int i = new_lms[k - 1], j = new_lms[k];
      if (vec[i] != vec[j]) {
        sa[j] = ++cur;
        continue;
      }
      bool flag = false;
      for (int a = i + 1, b = j + 1;; ++a, ++b) {
        if (vec[a] != vec[b]) {
          flag = true;
          break;
        }
        if ((!sl[a] && sl[a - 1]) ||
            (!sl[b] && sl[b - 1])) {
          flag = !((!sl[a] && sl[a - 1]) &&
                   (!sl[b] && sl[b - 1]));
          break;
        }
      }
      sa[j] = (flag ? ++cur : cur);
    }
    for (int i = 0; i < (int)lms.size(); i++)
      lms_vec[i] = sa[lms[i]];
    if (cur + 1 < (int)lms.size()) {
      auto lms_sa = build_sa(lms_vec, cur + 1);
      for (int i = 0; i < (int)lms.size(); i++)
        new_lms[i] = lms[lms_sa[i]];
    }
    induced_sort(vec, val, sa, sl, new_lms);
    return sa;
  }
  vector<int> suffix_array() {
    vector<int> vec(n + 1);
    copy(begin(s), end(s), begin(vec));
    vec.back() = '$';
    auto sa = build_sa(vec, 256);
    sa.erase(sa.begin());
    return sa;
  }

  vector<int> build_lcp() {
    int n = (int)s.size(), k = 0;
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;

    for (int i = 0; i < n; i++, k -= !!k) {
      if (rank[i] == n - 1) {
        k = 0;
        continue;
      }
      int j = sa[rank[i] + 1];
      while (i + k < n && j + k < n &&
             s[i + k] == s[j + k])
        k++;
      lcp[rank[i]] = k;
    }
    return lcp;
  }

  SA() {}

  SA(string s) : s(s), n((int)s.size()), pos(n) {
    sa = suffix_array();
    lcp = build_lcp();
    // //rmq = RMQ(lcp);
    // for(int i=0; i<n; i++) pos[sa[i]]=i;
  }

  int get_lcp(
      int i,
      int j) {  // lcp na posição i, indica o lcp
                // das posições i e i+1 do sa
    if (i == j) return n - i;
    int l = pos[i], r = pos[j];

    if (l > r) swap(l, r);

    // return rmq.query_min(l, r);
  }

  // string s = a + '+' + b;
  pair<int, int> lcs(
      int m) {  // m é o tamanho da string a
    int maior = 0, pos = -1;
    for (int i = 2; i < n; i++) {
      if ((sa[i] < m) != (sa[i - 1] < m)) {
        if (lcp[i - 1] > maior)
          maior = lcp[i - 1], pos = sa[i];
      }
    }
    return {maior, pos};
  }

  ll distinct_subs() {  // n*(n+1)/2 - sum(lcp[i])
    ll resp = (ll)n * ((ll)n + 1) / 2;
    return resp - accumulate(lcp.begin(),
                             lcp.end(), 0LL);
  }
};

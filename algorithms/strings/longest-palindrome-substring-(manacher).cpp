vi manacher(const string &s) {
  int n = len(s) - 2;
  vi p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (s[i - p[i]] == s[i + p[i]]) p[i]++;
    if (i + p[i] > r) l = i - p[i], r = i + p[i];
    p[i]--;
  }
  return p;
}
string longest_palindrome(const string &s) {
  string t("$#");
  for (auto c : s) t.push_back(c), t.push_back('#');
  t.push_back('^');
  vi xs = manacher(t);
  int mpos = max_element(all(xs)) - xs.begin();
  string p;
  for (int k = xs[mpos], i = mpos - k; i <= mpos + k; i++)
    if (t[i] != '#') p.push_back(t[i]);
  return p;
}

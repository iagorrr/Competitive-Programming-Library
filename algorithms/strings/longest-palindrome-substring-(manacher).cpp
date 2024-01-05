const ll oo = 1e18;
vi manacher(const string &s) {
  string t2;
  t2.push_back('$');
  for (auto c : s) {
    t2.push_back('#');
    t2.push_back(c);
  }
  t2.push_back('#');
  t2.push_back('^');
  int n = len(t2) - 2;  // bc of $ and ^
  vi p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (t2[i - p[i]] == t2[i + p[i]]) p[i]++;
    if (i + p[i] > r) l = i - p[i], r = i + p[i];
    p[i]--;
  }
  return vi(p.begin() + 1, p.end() - 1);
}
string longest_palindrome(const string &s) {
  vi xs = manacher(s);

  string s2;
  for (auto c : s) s2.push_back('#'), s2.push_back(c);
  s2.push_back('#');

  int mpos = max_element(all(xs)) - xs.begin();

  string ans;
  int k = xs[mpos];
  for (int i = mpos - k; i <= mpos + k; i++)
    if (s2[i] != '#') ans.push_back(s2[i]);

  return ans;
}

vi manacher(const string &s) {
  string t2;
  for (auto c : s) t2 += string("#") + c;
  t2 = t2 + '#';
  int n = t2.size();
  t2 = "$" + t2 + "^";
  vi p(n + 2);
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while (t2[i - p[i]] == t2[i + p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) {
      l = i - p[i], r = i + p[i];
    }
    p[i]--;
  }
  return vi(begin(p) + 1, end(p) - 1);
}
string longest_palindrome(const string &s) {
  vi xs = manacher(s);

  string s2;
  for (auto c : s) s2 += string("#") + c;
  s2 = s2 + '#';

  // refactor this to use cpp max and iterators arithmetic
  int mpos = 0;
  for (int i = 0; i < len(xs); i++) {
    if (xs[i] > xs[mpos]) {
      mpos = i;
    }
  }

  string ans;
  int k = xs[mpos];
  for (int i = mpos - k; i <= mpos + k; i++) {
    if (s2[i] != '#') {
      ans += s2[i];
    }
  }
  return ans;
}

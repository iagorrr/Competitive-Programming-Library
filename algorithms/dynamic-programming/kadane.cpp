int kadane(const vi &as) {
  vi s(len(as));
  s[0] = as[0];

  for (int i = 1; i < len(as); ++i)
    s[i] = max(as[i], s[i - 1] + as[i]);

  return *max_element(all(s));
}

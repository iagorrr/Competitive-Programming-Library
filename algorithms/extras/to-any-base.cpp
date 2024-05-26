vll to_otherbase(ll x, ll b) {
  vll result;

  while (x) {
    auto [quot, rem] = std::div(x, b);

    x = rem < 0 ? quot + 1 : quot;
    rem = rem < 0 ? rem + -b : rem;

    result.eb(rem);
  }

  if (!len(result)) return {0ll};

  reverse(all(result));

  // [msb, ..., lsb]
  return result;
}

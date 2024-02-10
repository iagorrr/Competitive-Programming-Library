template <typename T>
tuple<T, T, T> ext_gcd(T a, T b) {
  if (b == 0) return {a, 1, 0};

  auto [d, x1, y1] = ext_gcd(b, a % b);

  return {d, y1, x1 - y1 * (a / b)};
}

template <typename T>
tuple<bool, T, T> find_any_solution(T a, T b, T c) {
  assert(a != 0 or b != 0);
#warning Be careful with overflow, use __int128 if needed !

  auto [d, x0, y0] =
    ext_gcd(a < 0 ? -a : a, b < 0 ? -b : b);

  if (c % d) return {false, 0, 0};

  x0 *= c / d;
  y0 *= c / d;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;

  return {true, x0, y0};
}

// optional if you want to use __int128
void print(__int128 x) {
  if (x < 0) {
    cout << '-';
    x = -x;
  }
  if (x > 9) print(x / 10);
  cout << (char)((x % 10) + '0');
}

__int128 read() {
  string s;
  cin >> s;
  __int128 x = 0;
  for (auto c : s) {
    if (c != '-') x += c - '0';
    x *= 10;
  }
  x /= 10;
  if (s[0] == '-') x = -x;
  return x;
}

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

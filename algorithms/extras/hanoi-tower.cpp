void move(int a, int b) { cout << a << ' ' << b << endl; }
void solve(int n, int s, int e) {
  if (n == 0) return;
  if (n == 1) {
    move(s, e);
    return;
  }
  solve(n - 1, s, 6 - s - e);
  move(s, e);
  solve(n - 1, 6 - s - e, e);
}

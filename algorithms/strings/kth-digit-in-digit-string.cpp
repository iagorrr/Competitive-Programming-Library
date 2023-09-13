using vull = vector<ull>;
vull pow10;
vector<array<ull, 4>> memo;
void precompute(int maxpow = 18) {
  ull qtd = 1;
  ull start = 1;
  ull end = 9;
  ull curlenght = 9;
  ull startstr = 1;
  ull endstr = 9;

  for (ull i = 0, j = 1ll; (int)i < maxpow; i++, j *= 10ll) pow10.eb(j);

  for (ull i = 0; i < maxpow - 1ull; i++) {
    memo.push_back({start, end, startstr, endstr});

    start = end + 1ll;
    end = end + (9ll * pow10[qtd]);
    curlenght = end - start + 1ull;

    qtd++;
    startstr = endstr + 1ull;
    endstr = (endstr + 1ull) + (curlenght)*qtd - 1ull;
  }
}
char kthDigit(ull k) {
  int qtd = 1;
  for (auto [s, e, ss, es] : memo) {
    if (k >= ss and k <= es) {
      ull pos = k - ss;
      ull index = pos / qtd;
      ull nmr = s + index;
      int i = k - ss - qtd * index;

      return ((nmr / pow10[qtd - i - 1]) % 10) + '0';
    }
    qtd++;
  }

  return 'X';
}

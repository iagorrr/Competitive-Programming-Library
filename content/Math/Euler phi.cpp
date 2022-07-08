/*8<

  @Title: Euler Phi
  @Description:
    Computes the number of positive integers less
    than $N$ that are coprimes with $N$, in
    $O(\sqrt{N})$.
>8*/
int phi(int n) {
    if (n == 1) return 1;

    auto fs = factorization(n);  // a vctor of pair or a map
    auto res = n;

    for (auto [p, k] : fs) {
        res /= p;
        res *= (p - 1);
    }

    return res;
}

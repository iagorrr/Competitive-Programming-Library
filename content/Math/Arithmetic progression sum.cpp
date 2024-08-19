/*8<
  @Title: Arithmetic Progression Sum
  @Usage:
    \begin{compactitem}
      \item $s$ : first term
      \item $d$ : common difference
      \item $n$ : number of terms
    \end{compactitem}
>8*/
ll arithmeticProgressionSum(ll s, ll d, ll n) {
  return (s + (s + d * (n - 1))) * n / 2ll;
}

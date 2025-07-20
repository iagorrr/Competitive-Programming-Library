/*8<
        @Description: Given a binomial distribution with probabiliy $p$,
        find the probability of get exactly $k$ success in $n$ trials.

        @Warning: Not tested yet. Remember to call calc() before make queries.
>8*/

#include "../Contest/template.cpp"

namespace k_success {
const int MAX = 1e8;
double logfact[MAX];

void calc() {
    logfact[0] = 0;
    for (int i = 1; i < MAX; i++) logfact[i] = logfact[i - 1] + log(i);
}

double binom(int n, int k, double p) {
    return exp(logfact[n] - logfact[k] - logfact[n - k] + k * log(p) +
               (n - k) * log(1 - p));
}
};  // namespace k_success

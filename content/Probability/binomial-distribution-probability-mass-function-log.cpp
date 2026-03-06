/*8<
        @Description: Given a binomial distribution with find the probability of
        get exactly $k$ success in $n$ trials, where each try have a probability
        of success of $p$.

        @Warning: This is pure magic !. Remember to call calc() before make
        queries.
>8*/

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

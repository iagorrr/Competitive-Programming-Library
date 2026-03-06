/*8<
        @Description: Given a binomial distribution with find the probability of
        get exactly $k$ success in $n$ trials, where each try have a probability
        of success of $p$.

        @Warning: Remember to call precompute before make queries.
>8*/

const int max_tries = 500;
const int max_success_tries = 500;
long double mem[max_tries + 1][max_success_tries + 1];

void precompute(long double success_probability) {
    long double fail_probability = 1 - success_probability;

    for (int i = 1; i <= max_tries; i++) mem[0][i] = 0;
    mem[0][0] = 1.0;

    for (int i = 1; i <= max_tries; i++) {
        mem[i][0] = mem[i - 1][0] * fail_probability;

        for (int j = 1; j <= min(i, max_success_tries); j++) {
            long double from_prev_success =
                mem[i - 1][j - 1] * success_probability;
            long double from_prev_failure =
                (j < i) ? mem[i - 1][j] * fail_probability : 0.0;

            mem[i][j] = from_prev_success + from_prev_failure;
        }
    }
}

long double pmf(int n, int k) {
    if (k < 0 || k > n) return 0.0;
    return mem[n][k];
}

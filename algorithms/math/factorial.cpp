const ll MAX = 18;
vll fv(MAX, -1);
ll factorial(ll n) {
        if (fv[n] != -1) return fv[n];
        if (n == 0) return 1;
        return n * factorial(n - 1);
}

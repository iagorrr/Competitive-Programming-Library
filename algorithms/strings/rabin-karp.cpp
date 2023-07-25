vi rabin_karp(string const &s, string const &t) {
        ll p = 31;
        ll m = 1e9 + 9;
        int S = s.size(), T = t.size();

        vll p_pow(max(S, T));
        p_pow[0] = 1;
        for (int i = 1; i < (int)p_pow.size(); i++)
                p_pow[i] = (p_pow[i - 1] * p) % m;

        vll h(T + 1, 0);
        for (int i = 0; i < T; i++)
                h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
        ll h_s = 0;
        for (int i = 0; i < S; i++)
                h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

        vi occurences;
        for (int i = 0; i + S - 1 < T; i++) {
                ll cur_h = (h[i + S] + m - h[i]) % m;
                // IT DON'T CONSIDERE CONLISIONS !
                if (cur_h == h_s * p_pow[i] % m) occurences.push_back(i);
        }
        return occurences;
}

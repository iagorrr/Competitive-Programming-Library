vi lyndon_factorization(string S) {
    auto sa = suffix_array(S);
    vi ans;
    vi mex(len(S) + 1, 0);
    int p = 0;
    rtrav(si, sa) {
        if (si == p) {
            ans.eb(si);
        }
        mex[si] = 1;
        while (mex[p]) p++;
    }
    ans.eb(len(S));
    return ans;
}

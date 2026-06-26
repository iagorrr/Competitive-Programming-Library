""
    "
    HANOI

    void
    move_pilha(vpll &ans, ll N, ll from, ll to) {
    if (N == 1) {
        pll p{from, to};
        ans.push_back(p);
    } else {
        ll comp = 6 - from - to;
        move_pilha(ans, N - 1, from, comp);
        pll p{from, to};
        ans.pb(p);
        move_pilha(ans, N - 1, comp, to);
    }
}

ll M = sz(ans);  // qnt movimentos
ans{from, to}

HANOI Bagunçado

    void
    move_pilha(vpll &ans, ll N, vll &pos, ll to) {
    if (N == 0) return;
    ll from = pos[N];
    if (from == to) {
        move_pilha(ans, N - 1, pos, to);
    } else {
        ll comp = 6 - from - to;
        move_pilha(ans, N - 1, pos, comp);
        pll p{from, to};
        ans.pb(p);
        pos[N] = to;
        move_pilha(ans, N - 1, pos, to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vll pos(n + 1);
    rep(i, 1, 4) {
        ll t;
        cin >> t;
        rep(j, 0, t) {
            ll x;
            cin >> x;
            pos[x] = i;
        }
    }

    vpll ans;
    move_pilha(ans, n, pos, 2);

    ll M = sz(ans);
    ""
    "

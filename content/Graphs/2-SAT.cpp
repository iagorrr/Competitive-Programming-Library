/*8<
  @Description:

    Calculates a valid assignment to boolean
    variables a, b, c,... to a 2-SAT
    problem, so that an expression of the type
    $(a||b)\&\&(!a||c)\&\&(d||!b)\&\&...$ becomes
    true, or reports that it is unsatisfiable.

  @Usage:

    Negated variables are represented by
    bit-inversions (\texttt{$\tilde{}x$}).

    Returns true iff it is solvable
    ts.values[0..N-1] holds the assigned values
    to the vars.

  @Time:

    $O(N+E)$, where N is the number of boolean
    variables, and E is the number of clauses.

>8*/
//*8<
#pragma once
#include "../Contest/template.cpp"
//>8*/

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values;  // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    int addVar() {  // (optional)
        gr.eb();
        gr.eb();
        return N++;
    }

    void add_or(int x, int y) {
        x = max(2 * x, -1 - 2 * x);
        y = max(2 * y, -1 - 2 * y);
        gr[x].pb(y ^ 1);
        gr[y].pb(x ^ 1);
    }

    void add_true(int x) { add_or(x, x); }

    void add_impl(int f, int j) { add_or(~f, j); }  // (optional)

    void add_xor(int x, int y) {  // (optional) not tested yet
        add_or(x, y), add_or(~x, ~y);
    }

    void add_eq(int x, int y) {  // (optional) not tested yeat
        add_xor(~x, y);
    }

    void at_most_one(const vi &li) {  // (optional)
        if (len(li) <= 1) return;
        int cur = ~li[0];
        rep(i, 2, len(li)) {
            int next = addVar();
            add_or(cur, ~li[i]);
            add_or(cur, next);
            add_or(~li[i], next);
            cur = ~next;
        }
        add_or(cur, ~li[1]);
    }

    vi val, comp, z;
    int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x;
        z.pb(i);
        for (int e : gr[i])
            if (!comp[e]) low = min(low, val[e] ?: dfs(e));
        if (low == val[i]) do {
                x = z.back();
                z.ppb();
                comp[x] = low;
                if (values[x >> 1] == -1) values[x >> 1] = x & 1;
            } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0);
        comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

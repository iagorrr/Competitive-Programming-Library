using ll = long long;

const ll MOD = 998244353;

inline ll sum(const ll a, const ll b) { return (a + b) % MOD; }

ll sub(const ll a, const ll b) { return (a - b + MOD) % MOD; }

inline ll mul(const ll a, const ll b) { return (a * b) % MOD; }

struct SqrtDecomposition {
    struct t_sqrt {
        int l, r;
        ll x, y;
        ll prod;
        ll sum_as, sum_bs;

        t_sqrt() {
            l = numeric_limits<int>::max();
            r = numeric_limits<int>::min();
            x = y = prod = sum_as = sum_bs = 0;
        };
    };

    int sqrtLen;
    vector<t_sqrt> blocks;
    vector<ll> as, bs;
    SqrtDecomposition(const vector<ll> &as_, const vector<ll> &bs_) {
        int n = as_.size();
        sqrtLen = (int)sqrt(n + .0) + 1;
        blocks.resize(sqrtLen + 6.66);
        as = as_;
        bs = bs_;

        for (int i = 0; i < n; i++) {
            auto &bi = blocks[i / sqrtLen];

            bi.l = min(bi.l, i);
            bi.r = max(bi.r, i);
            bi.sum_as = sum(bi.sum_as, as[i]);
            bi.sum_bs = sum(bi.sum_bs, bs[i]);
            bi.prod = sum(bi.prod, mul(as[i], bs[i]));
        }
    }

    // adds x to a[i], and y to b[i], in range [l,
    // r]
    void update(int l, int r, ll x, ll y) {
        auto apply1 = [&](int idx, ll x, ll y) -> void {
            auto &block = blocks[idx / sqrtLen];

            block.prod = sub(block.prod, mul(as[idx], bs[idx]));
            block.sum_as = sub(block.sum_as, as[idx]);
            block.sum_bs = sub(block.sum_bs, bs[idx]);

            as[idx] = sum(as[idx], x);
            bs[idx] = sum(bs[idx], y);

            block.prod = sum(block.prod, as[idx] * bs[idx]);
            block.sum_as = sum(block.sum_as, as[idx]);
            block.sum_bs = sum(block.sum_bs, bs[idx]);
        };

        auto apply2 = [&](int idx, ll x, ll y) -> void {
            blocks[idx].x = sum(blocks[idx].x, x);
            blocks[idx].y = sum(blocks[idx].y, y);
        };

        int cl = l / sqrtLen, cr = r / sqrtLen;

        if (cl == cr) {
            for (int i = l; i <= r; i++) {
                apply1(i, x, y);
            }
        } else {
            for (int i = l; i <= (cl + 1) * sqrtLen - 1; i++) {
                apply1(i, x, y);
            }

            for (int i = cl + 1; i <= cr - 1; i++) {
                apply2(i, x, y);
            }

            for (int i = cr * sqrtLen; i <= r; i++) {
                apply1(i, x, y);
            }
        }
    }

    // sum of a[i]*b[i] in range [l  r]
    ll query(int l, int r) {
        auto eval1 = [&](int idx) -> ll {
            auto &block = blocks[idx / sqrtLen];
            return mul(sum(as[idx], +block.x), sum(bs[idx], block.y));
        };

        auto eval2 = [&](int idx) -> ll {
            auto &block = blocks[idx];

            ll ret = 0;
            ret = sum(
                ret, mul(mul(block.x, block.y), sum(sub(block.r, block.l), 1)));
            ret = sum(ret, block.prod);
            ret = sum(ret, block.y * block.sum_as);
            ret = sum(ret, block.x * block.sum_bs);

            return ret;
        };

        ll ret = 0;
        int cl = l / sqrtLen, cr = r / sqrtLen;
        if (cl == cr) {
            for (int i = l; i <= r; i++) {
                ret = sum(ret, eval1(i));
            }
        } else {
            for (int i = l; i <= (cl + 1) * sqrtLen - 1; i++) {
                ret = sum(eval1(i), ret);
            }

            for (int i = cl + 1; i <= cr - 1; i++) {
                ret = sum(ret, eval2(i));
            }

            for (int i = cr * sqrtLen; i <= r; i++) {
                ret = sum(ret, eval1(i));
            }
        }

        return ret;
    }
};

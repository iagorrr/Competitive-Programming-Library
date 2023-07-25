template <ll MOD = 998'244'353>
struct Modular {
        int value;
        static const int MOD_value = MOD;

        Modular(ll v = 0) {
                value = v % MOD;
                if (value < 0) value += MOD;
        }
        Modular(ll a, ll b) : value(0) {
                *this += a;
                *this /= b;
        }

        Modular& operator+=(Modular const& b) {
                value += b.value;
                if (value >= MOD) value -= MOD;
                return *this;
        }
        Modular& operator-=(Modular const& b) {
                value -= b.value;
                if (value < 0) value += MOD;
                return *this;
        }
        Modular& operator*=(Modular const& b) {
                value = (ll)value * b.value % MOD;
                return *this;
        }

        friend Modular mexp(Modular a, ll e) {
                Modular res = 1;
                while (e) {
                        if (e & 1) res *= a;
                        a *= a;
                        e >>= 1;
                }
                return res;
        }
        friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

        Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
        friend Modular operator+(Modular a, Modular const b) { return a += b; }
        friend Modular operator-(Modular a, Modular const b) { return a -= b; }
        friend Modular operator-(Modular const a) { return 0 - a; }
        friend Modular operator*(Modular a, Modular const b) { return a *= b; }
        friend Modular operator/(Modular a, Modular const b) { return a /= b; }
        friend std::ostream& operator<<(std::ostream& os, Modular const& a) {
                return os << a.value;
        }
        friend bool operator==(Modular const& a, Modular const& b) {
                return a.value == b.value;
        }
        friend bool operator!=(Modular const& a, Modular const& b) {
                return a.value != b.value;
        }
};

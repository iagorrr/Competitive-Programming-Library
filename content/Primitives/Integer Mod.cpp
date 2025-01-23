#include "../Contest/template.cpp"

template <ll m>
struct mod_int {
    ll x;

    mod_int(ll v = 0) {
        x = v % m;
        if (x < 0) v += m;
    }

    mod_int &operator+=(mod_int const &b) {
        x += b.x;
        if (x >= m) x -= m;
        return *this;
    }

    mod_int &operator-=(mod_int const &b) {
        x -= b.x;
        if (x < 0) x += m;
        return *this;
    }
    mod_int &operator*=(mod_int const &b) {
        x = (ll)x * b.x % m;
        return *this;
    }

    friend mod_int mpow(mod_int a, ll e) {
        mod_int res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend mod_int inverse(mod_int a) { return mpow(a, m - 2); }

    mod_int &operator/=(mod_int const &b) { return *this *= inverse(b); }
    friend mod_int operator+(mod_int a, mod_int const b) { return a += b; }
    mod_int operator++(int) { return this->x = (this->x + 1) % m; }
    mod_int operator++() { return this->x = (this->x + 1) % m; }
    friend mod_int operator-(mod_int a, mod_int const b) { return a -= b; }
    friend mod_int operator-(mod_int const a) { return 0 - a; }
    mod_int operator--(int) { return this->x = (this->x - 1 + m) % m; }

    mod_int operator--() { return this->x = (this->x - 1 + m) % m; }
    friend mod_int operator*(mod_int a, mod_int const b) { return a *= b; }
    friend mod_int operator/(mod_int a, mod_int const b) { return a /= b; }
    friend ostream &operator<<(ostream &os, mod_int const &a) {
        return os << a.x;
    }
    friend bool operator==(mod_int const &a, mod_int const &b) {
        return a.x == b.x;
    }
    friend bool operator!=(mod_int const &a, mod_int const &b) {
        return a.x != b.x;
    }
};


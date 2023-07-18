#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define all(__x) __x.begin(), __x.end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<pll> ans(n);
    for(int i = 0; i < n ;++i) {
        vll notas(7);

        string d; cin >> d;
        char l = d.back();
        d.pop_back();
        d.pop_back();
        d += l;
        ll diff = stoll(d);
        for(int j = 0; j < 7; ++j) {
            string tmp; cin >> tmp;
            char last = tmp.back();
            tmp.pop_back();
            tmp.pop_back();
            tmp += last;
            notas[j] = stoll(tmp);
        }

        sort(all(notas));

        ll sum = 0;
        for (int j = 2; j <= 4; j++) {
            sum += notas[j];
        }

        sum *= diff;

        ans[i] = make_pair(-sum, i + 1);

    }

    sort(all(ans));

    for (auto [a, b] : ans) {
        cout << b << ' ' << (-a / 100) << "." << (-a % 100) / 10 << '\n';
    }

    return 0;
}

// AC, implementation

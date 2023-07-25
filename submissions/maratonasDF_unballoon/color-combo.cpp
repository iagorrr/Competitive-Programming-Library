// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
        ll t;
        cin >> t;
        for (int i = 1; i <= t; ++i) {
                ll b, n;
                cin >> b >> n;
                ll a = b;
                a += 100 * max(0ll, n - 3);
                if (n > 7) {
                        a += a / 2;
                } else if (n > 3) {
                        a += a / 4;
                }
                string str = " ponto";
                if (a > 1) str = " pontos";
                cout << "Caso " << i << ": " << a << str << '\n';
        }
}

// AC-math

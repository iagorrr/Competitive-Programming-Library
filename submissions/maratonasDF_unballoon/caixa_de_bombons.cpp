#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c; cin >> a >> b >> c;

    ll bombons_a = (a / 5);

    a -= bombons_a * 5;
    b -= bombons_a * 25;
    c -= bombons_a * 20;

    ll bombons_b = (b / 25);

    b -= bombons_b * 25;
    c -= bombons_b * 25;

    ll bombons_c = (c / 50);

    ll qnt_c = min({bombons_a, bombons_b, bombons_c}) / 10;
    
    bombons_a -= qnt_c * 10;
    bombons_b -= qnt_c * 10;
    bombons_c -= qnt_c * 10;
     
    ll qnt_b = min(bombons_a / 10, bombons_b / 20);
    
    bombons_a -= qnt_b * 10;
    bombons_b -= qnt_b * 20;

    ll qnt_a = bombons_a / 30; 

    cout << qnt_a << ' ' << qnt_b << ' ' << qnt_c << '\n';

    return 0;
}

// AC, math

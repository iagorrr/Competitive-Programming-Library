#include <bits/stdc++.h>
using namespace std;

auto run() {
        string s;
        cin >> s;

        using ll = long long;
        ll k = 0;
        ll p10 = 100;
        for (int i = 3; i < 6; i++) {
                k += ((s[i]-'0') * p10);
                p10 /= 10;

        }
        if (k < 350 and k != 316 and k != 0)  {
                cout << "Yes\n";
        
        }
        else {
                cout << "No\n";
        }

}

int32_t main() {
        run();        
}

// AC, ad-hoc

#include <bits/stdc++.h>
using namespace std;

auto run() {
        int n, q;
        cin >> n >> q;
        set<int> xs;
        for (int i = 1; i <= n; i++) {
                xs.emplace(i);
        }

        while(q--) {
                int xi; 
                cin >> xi;

                if (xs.find(xi) != xs.end()) xs.erase(xi);
                else xs.emplace(xi);
        }

        cout << xs.size() << '\n';
}

int32_t main() {
        run();        
}

// AC, ad-hoc

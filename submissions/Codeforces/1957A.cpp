#include <bits/stdc++.h>
using namespace std;

auto run() {
        int n;
        cin >> n;

        map<int,int> h;
        for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                h[x]++;
        }

        int ans = 0;
        for (auto [_, q] : h) {
                ans += q / 3;
        }
        cout << ans << '\n';
        
}

int main()  {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int  t;
        cin >> t;
        while (t--){
                run();
        }
}
 

// AC, constructive algorithms, greddy

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> xs(n);
        for (int i = 0;i < n; i++) {
                xs[i] = s[i] - '0';
        }

        map<int,int> hist;
        hist[0] = 1;

        ll ans = 0;
        for (int i = 0, s = 0; i < n;  i++) {
                s += xs[i];
                int s2 = s - i -1;
                ans += hist[s2];
                hist[s2]++;
        }

        cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;;

	while (tt--)
		run();
}

// AC, math, dp

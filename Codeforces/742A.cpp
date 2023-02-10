// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int solve(int n){
    if (!n) return 1;
    vi a {6, 8, 4, 2};
    return a[n%4];
}
int32_t main(void){ fastio;
    int n; cin >> n;
    cout << solve(n) <<  '\n';
}
// AC, math.

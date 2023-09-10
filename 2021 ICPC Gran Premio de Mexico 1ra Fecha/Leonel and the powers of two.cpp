#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

string foo(ll k)
{
    if (k == 1)
        return "2";

    if (k & 1)
        return "(2*" + foo(k - 1) + ")";

    return "(" + foo(k>>1) + ")^2";
}

void run()
{
    ll k;
    cin >> k;
    cout << foo(k) << '\n';
}

int32_t main(){
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        run();
}
// AC, math

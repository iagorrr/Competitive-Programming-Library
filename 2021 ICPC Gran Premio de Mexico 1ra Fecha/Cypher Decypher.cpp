#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

bool is_prime(ll x)
{
    for (int i = 2; i*i <= x; i++)
        if (x%i==0)
            return false;
    return true;
}

vector<ll> ps(1e6 + 20);
void run()
{
    int l, r;
    cin >> l >> r;
    cout << ps[r] - ps[l-1] << '\n';
}

int32_t main(){
    fastio;
    int t;
    cin >> t;
    for (int i = 2; i < len(ps); i++)
    {
        ps[i] = ps[i-1];
        if (is_prime(i))
            ps[i]++;
    }
    while (t--)
        run();
}

// AC, math

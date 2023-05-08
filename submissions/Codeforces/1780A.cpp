// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

void solve(const vector<ll> o, const vector<ll> e)
{
    if(o.size() >= 3)
    {

        cout << "YES\n";
        for(int i = 0; i < 3; ++i) cout << o[i] << ' '; cout << '\n';
        return;
    }

    if(o.size() >= 1 and e.size() >= 2)
    {
        cout << "YES\n";
        cout << o.front() << ' ' << e[0] << ' ' << e[1] << '\n';
        return;
    }

    cout << "NO\n";

}
int main(void){ 
    //fastio;
    ll t; cin >> t;

    while(t--)
    {
        ll n; cin >> n;
        vector<ll> o;
        vector<ll> e;

        for(int i = 1; i <= n; ++i)
        {
            ll x; cin >> x;
            if(x&1) o.push_back(i);
            else e.push_back(i);

        }

        solve(o, e);
    }
}

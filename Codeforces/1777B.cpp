// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
const ll mod = (ll)1e9 + 7;
ll fat(ll x)
{
    ll ans = 1;
 
    for(int i = 1; i <= x; ++i)
    {
        ans = (ans*i) % mod;
    }
    return ans;
}
ll solve(ll n)
{
    ll inver = 0;
    for(ll i = n*2 - 2; i >= 0; i -= 2)
    {
        inver += i;
    }
    //cout << "n: " << n << " i: " << inver << " f: " << fat(n) << '\n';
    ll ans = ((inver%mod) * (fat(n))) % mod;
    return ans;
}
int main(){ 
   fastio;
 
    ll t;
    cin >> t;
 
    while(t--)
    {
        ll n;
        cin >> n;
 
        cout << solve(n) << '\n';
    }
    return 0;
}
// AC.
